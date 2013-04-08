#include "QWDevice.h"

#include <qxmpp/QXmppConfiguration.h>
#include <qxmpp/QXmppMessage.h>

#include <QHostInfo>

QWDevice::QWDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QXmppClient(parent), _configuration(configuration)
{
#ifdef QT_DEBUG
    logger()->setLoggingType(QXmppLogger::StdoutLogging);
#endif
    _mucManager = new QXmppMucManager;
    addExtension(_mucManager);
    QXmppConfiguration *conf = dynamic_cast<QXmppConfiguration*>(&_configuration);
#ifdef QT_DEBUG
    if(conf == NULL){
        qDebug() << "Invalid cast";
    }
#endif
    connectToServer(*conf);

    connect(this, SIGNAL(connected()), this, SLOT(startChat()));
}

void QWDevice::addActuator(QWActuator &actuator)
{
    foreach (QString st, actuator.getSubtypes()) {
        _actuators->insert(st, QSharedPointer<QWActuator>(&actuator));
    };
}

void QWDevice::startChat()
{
    _room = _mucManager->addRoom(_configuration.roomJid());
    _room->setNickName(configuration().jid());
    _room->join();

    connect(_room, SIGNAL(participantAdded(QString)), this, SLOT(addDevice(QString)));
    connect(_room, SIGNAL(messageReceived(QXmppMessage)), this, SLOT(parseMessage(QXmppMessage)));
}

void QWDevice::addDevice(const QString &jid)
{
#ifdef QT_DEBUG
    qDebug() << "Adding new Device: " << jid;
#endif
}

void QWDevice::parseMessage(const QXmppMessage &message)
{
#ifdef QT_DEBUG
    qDebug() << "Message recived: " << message.body();
#endif
}
