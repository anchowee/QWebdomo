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
    QList<QWActuator *> actuators;
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
    if(!d->actuators.contains(actuator)){
        d->actuators.append(actuator);
    }
}

void QWControlDevice::parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content)
{
    //Check if i can handle this message
    if(type != "GET" && type != "PUT") return;
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
    QList<QWActuator *>::iterator i;
    if(type == "GET"){ //the response will be sent only to the caller
        for(i = d->actuators.begin(); i != d->actuators.end(); i++){
            const QString resp = (*i)->get(st, cmds);
            if(!resp.isEmpty()){
                sendMessage(senderJid, resp);
            }
        }
    } else { // type == PUT => the response is sent on the group chat
        for(i = d->actuators.begin(); i != d->actuators.end(); i++){
            const QString resp = (*i)->put(st, cmds);
            if(!resp.isEmpty()){
                emit sendRoomMessage(resp);
            }
        }
    }

}
