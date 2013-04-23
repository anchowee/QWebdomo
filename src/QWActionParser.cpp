/*
 * Copyright 2013 Riccardo Ferrazzo <f.riccardo87@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
