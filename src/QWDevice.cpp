#include "QWDevice.h"

#include <qxmpp/QXmppConfiguration.h>
#include <qxmpp/QXmppMessage.h>

#include <QHostInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class QWDevicePrivate {
public:
    QWDevicePrivate(const QWDeviceConfiguration &conf) :
        configuration(conf) {}

    QHash<QString, QSharedPointer<const QWActuator> > actuators;
    QWDeviceConfiguration configuration;
    QXmppMucManager mucManager;
};

QWDevice::QWDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QXmppClient(parent), d(new QWDevicePrivate(configuration))
{
#ifdef QT_DEBUG
    logger()->setLoggingType(QXmppLogger::StdoutLogging);
#endif
    addExtension(&d->mucManager);
    QXmppConfiguration *conf = dynamic_cast<QXmppConfiguration*>(&d->configuration);
    connectToServer(*conf);

    connect(this, SIGNAL(connected()), this, SLOT(startChat()));
}

QWDevice::~QWDevice()
{
    delete d;
}

void QWDevice::addActuator(const QWActuator &actuator)
{
    QStringList subtypes = actuator.getSubtypes();
    foreach (QString st, subtypes) {
        d->actuators.insert(st, QSharedPointer<const QWActuator>(&actuator));
    };
}

void QWDevice::executeQuery(const QStringList &subtypes, const QHash<QString, QVariant> &commands)
{
#ifdef QT_DEBUG
    qDebug() << "Executing query";
#endif
    QList<QSharedPointer<const QWActuator> > matches = d->actuators.values(subtypes[0]);
    for(int i = 1; i<subtypes.length(); i++){
        foreach(QSharedPointer<const QWActuator> ptr, d->actuators.values(subtypes[i])){
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
    QXmppMucRoom *room = d->mucManager.addRoom(d->configuration.roomJid());
    room->setNickName(configuration().jid());
    room->join();

    connect(room, SIGNAL(participantAdded(QString)), this, SLOT(addDevice(QString)));
    connect(room, SIGNAL(messageReceived(QXmppMessage)), this, SLOT(parseMessage(QXmppMessage)));
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

void QWDevice::sendMessage(const QString &bareJid, ActionType action, const QJsonValue &content)
{
    QJsonObject jObject;
    jObject.insert("action", QJsonValue(int(action)));
    jObject.insert("content", content);
    QString message(QJsonDocument(jObject).toJson());
    sendMessage(bareJid, message);
}
