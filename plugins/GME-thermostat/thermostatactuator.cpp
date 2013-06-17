#include "thermostatactuator.h"

#include <math.h>

ThermostatActuator::ThermostatActuator(QObject *parent) :
    QWActuator(parent)
{
    _serial = new QSerialPort(this);
    _firstByte = -1;
    connect(_serial, SIGNAL(readyRead()), this, SLOT(getDeviceResponse()));
}

ThermostatActuator::~ThermostatActuator()
{
    _serial->close();
}

void ThermostatActuator::initialize()
{
    _serial->setPortName(var("serial").toString());
    _serial->setBaudRate(19200);
    _serial->setDataBits(QSerialPort::Data8);
    _serial->setParity(QSerialPort::EvenParity);
    _serial->setStopBits(QSerialPort::OneStop);
    _serial->open(QIODevice::ReadWrite);
}

void ThermostatActuator::get(const QString &senderJid, const QStringList &subtypes, const QHash<QString, QVariant> &attributes)
{
    Q_UNUSED(attributes);
    _lastSender = senderJid;
    QList<QSharedPointer<QWAppliance> > found = find(subtypes);
    QList<QSharedPointer<QWAppliance> >::iterator i;
    for(i = found.begin(); i != found.end(); i++){
        const QVariant id = (*i)->getAttribute("id");
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out << 0x47 << qint8(id.toInt());
        _serial->write(data);
    }
}

void ThermostatActuator::changeState(QList<QSharedPointer<QWAppliance> > *selectedAppliances, const QHash<QString, QVariant> &newStates)
{
    QList<QSharedPointer<QWAppliance> >::iterator i;
    for(i = selectedAppliances->begin(); i != selectedAppliances->end(); i++){
        const qint8 id = (*i)->getAttribute("id").toInt();
        const double temperature = newStates.value("temperature").toDouble();
        double tempInt;
        qint8 tempFloat;
        tempFloat = int(modf(temperature, &tempInt)*10);
        tempFloat *= 10;
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out << 0x53
            << qint8(newStates.value("state").toInt())
            << qint8(newStates.value("mode").toInt())
            << int(tempInt) << tempFloat << id;
        _serial->write(data);
    }
}

void ThermostatActuator::getDeviceResponse()
{
    QDataStream in(_serial);

    if(_firstByte == -1){
        in >> _firstByte;
    }

    const int dataSize = (_firstByte == 0x53) ? 1 : 7;
    if(_serial->bytesAvailable() < dataSize) return;

    if(_firstByte == 0x53){
        qint8 tId;
        in >> tId;

        QHash<QString, QVariant> vars;
        vars.insert("id", tId);
        emit notifyPut(formatResponse("PUT", find(QStringList(), vars)));
    } else {
        qint8 state = dataSize, mod, setTempInt, setTempFloat, tempInt, tempFloat, relayState, tId;
        in >> mod;
        in >> setTempInt;
        in >> setTempFloat;
        in >> tempInt;
        in >> tempFloat;
        in >> relayState;
        in >> tId;
        double setTemp = setTempInt + (setTempFloat * 0.1);
        double temp = tempInt + (tempFloat * 0.1);

        QHash<QString, QVariant> vars;
        vars.insert("id", tId);
        QList<QSharedPointer<QWAppliance> > apps = find(QStringList(), vars);
        QList<QSharedPointer<QWAppliance> >::iterator i;
        for(i = apps.begin(); i != apps.end(); i++){
            (*i)->setAttribute("state", state);
            (*i)->setAttribute("mode", mod);
            (*i)->setAttribute("setTemperature", setTemp);
            (*i)->setAttribute("temperature", temp);
            (*i)->setAttribute("relay", relayState);
        }
        emit notifyGet(_lastSender, formatResponse("GET", apps));
    }

    _firstByte = -1;
}
