#include "QWControlDevice.h"

#include <QSharedPointer>
#include <QJsonObject>
#include <QJsonArray>
#include <QMultiHash>
#ifdef QT_DEBUG
#include <QDebug>
#endif

class QWControlDevicePrivate {
public:
    QWControlDevicePrivate(){}
    QMultiHash<QString, QWActuator *> actuators;
};

QWControlDevice::QWControlDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QWDevice(configuration, parent), d(new QWControlDevicePrivate)
{
}

QWControlDevice::~QWControlDevice()
{
    delete d;
}

void QWControlDevice::addActuator(QWActuator *actuator)
{
    const QStringList subtypes = actuator->getSubtypes();
    QStringList::const_iterator it;
    for(it = subtypes.constBegin(); it != subtypes.constEnd(); ++it) {
        const QString st = *it;
        d->actuators.insert(st, actuator);
    };
}

void QWControlDevice::parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content)
{
#ifdef QT_DEBUG
    qDebug() << "Parsing message";
    qDebug() << "Call type: " << type << " Content: " << content.stringData;
#endif

    //Check if i can handle this message
    if(type != "GET" || type != "PUT") return;
    if(!content.isObject()) return;

    QJsonObject obj = content.toObject();

    //Getting subtypes
    QStringList st;
    const QJsonValue subtypes = obj.value("subtypes");
    if(subtypes.isArray()){
        QJsonArray stArray = subtypes.toArray();
        for(int i=0; i< stArray.size(); i++){
            if(stArray.at(i).isString()){
                st.append(stArray.at(i).toString());
            }
        }
    }
#ifdef QT_DEBUG
    qDebug() << "subtypes length: " << st.length();
#endif

    //Getting commands
    QHash<QString, QVariant> cmds;
    QJsonValue commands = obj.value("commands");
    if(commands.isObject()){
        QJsonObject cmdObj = commands.toObject();
        foreach(QString k, cmdObj.keys()){
            cmds.insert(k, cmdObj.value(k).toVariant());
        }
    }

    //Executing the command on the selected actuators
    QList<QWActuator *> matches = d->actuators.values(st[0]);
    for(int i = 1; i<st.length(); i++){
        foreach(QWActuator *ptr, d->actuators.values(st[i])){
            if(!matches.contains(ptr)){
                matches.removeAll(ptr);
            }
        }
    }
    if(st.length() == 0){
#ifdef QT_DEBUG
        qDebug() << "subtypes empty";
#endif
        const QList<QWActuator *> allMatches = d->actuators.values();
        QList<QWActuator *>::const_iterator it;
        for(it = allMatches.constBegin(); it != allMatches.constEnd(); ++it){
            QWActuator *ptr = *it;
            if(!matches.contains(ptr)){
                matches.append(ptr);
            }
        }
    }
    if(matches.length() > 0){
        foreach(QWActuator *ptr, matches){
            if(type == "GET"){
                //if it is a GET message inform only the sender
                sendMessage(senderJid, ptr->doGet(st, cmds));
            } else {
                emit sendRoomMessage(ptr->doPut(st, cmds));
            }
        }
    }

}
