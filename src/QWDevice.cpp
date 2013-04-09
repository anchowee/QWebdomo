#include "QWDevice.h"

#include <qxmpp/QXmppConfiguration.h>
#include <qxmpp/QXmppMessage.h>

#include <QHostInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QWDevice::QWDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QXmppClient(parent), _configuration(configuration)
{
#ifdef QT_DEBUG
    logger()->setLoggingType(QXmppLogger::StdoutLogging);
#endif
    _actuators = new QHash<QString, QSharedPointer<const QWActuator> >();
    _mucManager = new QXmppMucManager;
    addExtension(_mucManager);
    QXmppConfiguration *conf = dynamic_cast<QXmppConfiguration*>(&_configuration);
    connectToServer(*conf);

    connect(this, SIGNAL(connected()), this, SLOT(startChat()));
}

QWDevice::~QWDevice()
{
    delete _actuators;
    delete _mucManager;
}

void QWDevice::addActuator(const QWActuator &actuator)
{
    QStringList subtypes = actuator.getSubtypes();
    foreach (QString st, subtypes) {
        _actuators->insert(st, QSharedPointer<const QWActuator>(&actuator));
    };
}

void QWDevice::executeQuery(const QStringList &subtypes, const QHash<QString, QVariant> &commands)
{
#ifdef QT_DEBUG
    qDebug() << "Executing query";
#endif
    QList<QSharedPointer<const QWActuator> > matches = _actuators->values(subtypes[0]);
    for(int i = 1; i<subtypes.length(); i++){
        foreach(QSharedPointer<const QWActuator> ptr, _actuators->values(subtypes[i])){
            if(!matches.contains(ptr)){
                matches.removeAll(ptr);
            }
        }
    }
    if(matches.length() > 0){
        foreach(QSharedPointer<const QWActuator> ptr, matches){
            ptr->put(subtypes, commands);
        }
    }
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

    QJsonDocument doc = QJsonDocument::fromBinaryData(message.body().toUtf8());
    QJsonObject obj = doc.object();

    //TODO: add parser object to allow extensible parsing capabilities
    QStringList st;
    QJsonValue subtypes = obj.value("subtypes");
    if(subtypes.isArray()){
        QJsonArray stArray = subtypes.toArray();
        for(int i=0; i< stArray.size(); i++){
            if(stArray.at(i).isString()){
                st.append(stArray.at(i).toString());
            }
        }
    }

    QHash<QString, QVariant> cmds;
    QJsonValue commands = obj.value("commands");
    if(commands.isObject()){
        QJsonObject cmdObj = commands.toObject();
        foreach(QString k, cmdObj.keys()){
            cmds.insert(k, cmdObj.value(k).toVariant());
        }
    }
    executeQuery(st, cmds);
}
