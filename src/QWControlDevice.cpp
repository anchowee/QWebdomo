#include "QWControlDevice.h"

#include <QSharedPointer>
#include <QJsonObject>
#include <QJsonArray>

class QWControlDevicePrivate {
public:
    QHash<QString, QSharedPointer<const QWActuator> > actuators;
};

QWControlDevice::QWControlDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QWDevice(configuration, parent)
{
}

QWControlDevice::~QWControlDevice()
{
    delete d;
}

void QWControlDevice::addActuator(const QWActuator &actuator)
{
    QStringList subtypes = actuator.getSubtypes();
    foreach (QString st, subtypes) {
        d->actuators.insert(st, QSharedPointer<const QWActuator>(&actuator));
    };
}

void QWControlDevice::parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content)
{
    //Check if i can handle this message
    if(type != "GET" || type != "PUT") return;
    if(!content.isObject()) return;

    QJsonObject obj = content.toObject();

    //Getting subtypes
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
    QList<QSharedPointer<const QWActuator> > matches = d->actuators.values(st[0]);
    for(int i = 1; i<st.length(); i++){
        foreach(QSharedPointer<const QWActuator> ptr, d->actuators.values(st[i])){
            if(!matches.contains(ptr)){
                matches.removeAll(ptr);
            }
        }
    }
    if(matches.length() > 0){
        foreach(QSharedPointer<const QWActuator> ptr, matches){
            if(type == "GET"){
                //if it is a GET message inform only the sender
                sendMessage(senderJid, ptr->doGet(st, cmds));
            } else {
                sendMessage(roomJid(), ptr->doPut(st, cmds));
            }
        }
    }

}
