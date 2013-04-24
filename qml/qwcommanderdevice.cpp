#include "qwcommanderdevice.h"

QWCommanderDevice::QWCommanderDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QWDevice(configuration, parent)
{
}

void QWCommanderDevice::parseMessage(const QString &type, const QJsonValue &content)
{
    if(type != "NOTIFY") return;
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

    emit updateAppliances(st, cmds);
}
