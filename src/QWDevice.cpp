#include "QWDevice.h"

#include <qxmpp/QXmppConfiguration.h>

#include <QHostInfo>

QWDevice::QWDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QXmppClient(parent), _configuration(configuration)
{
#ifdef QT_DEBUG
    logger()->setLoggingType(QXmppLogger::StdoutLogging);
#endif
    _mucManager = new QXmppMucManager;
    addExtension(_mucManager);

    connect(this, SIGNAL(connected()), this, SLOT(startChat()));
    QXmppConfiguration *conf = dynamic_cast<QXmppConfiguration*>(&_configuration);
#ifdef QT_DEBUG
    if(conf == NULL){
        qDebug() << "Invalid cast";
    }
#endif
    connectToServer(*conf);
}

void QWDevice::startChat()
{
    QXmppMucRoom *_room = _mucManager->addRoom(_configuration.roomJid());
    _room->setNickName(configuration().jid());
    _room->join();
}
