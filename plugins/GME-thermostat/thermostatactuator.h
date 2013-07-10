#ifndef THERMOSTATACTUATOR_H
#define THERMOSTATACTUATOR_H

#include "QWActuator.h"
#include <QtSerialPort/QSerialPort>

class ThermostatActuator : public QWActuator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Webdomo.Plugin.QWActuator/1.0" FILE "GME-thermostatActuator.json")
    Q_INTERFACES(QWActuator)
public:
    explicit ThermostatActuator(QObject *parent = 0);
    ~ThermostatActuator();
    
    void initialize();
    void get(const QString &senderJid, const QStringList &subtypes, const QHash<QString, QVariant> &attributes);
    void changeState(QList<QSharedPointer<QWAppliance> > *selectedAppliances, const QHash<QString, QVariant> &newStates);

private slots:
    void getDeviceResponse();

private:
    QSerialPort *_serial;
    qint8 _firstByte;
    QString _lastSender; //FIXME: find a more reliable way to keep it in memory
};

#endif // THERMOSTATACTUATOR_H
