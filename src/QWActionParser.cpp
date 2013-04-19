#include "QWActionParser.h"

#include <QJsonObject>
#include <QJsonArray>

QWActionParser::QWActionParser(QObject *parent) :
    QWParser(parent)
{
}

void QWActionParser::parse(const QString &bareJid, QWParser::MessageType type, const QJsonValue &content)
{
    //Check if i can handle this message
    if(type != GetMessage || type != PutMessage) return;
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

    //Emit the proper signal
    if(type == GetMessage){
        emit doGet(st, cmds);
        return;
    }
    emit doPut(st, cmds);
}
