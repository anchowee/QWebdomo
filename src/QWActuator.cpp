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

#include "QWActuator.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

QWActuator::QWActuator(QObject *parent) :
    QObject(parent)
{}

QStringList QWActuator::getSubtypes() const
{
    QStringList subtypes;
    for(int i = 0; i < _appliances->length(); i++){
        subtypes.append(_appliances->at(i).subtypes());
    }
    return subtypes;
}

QString QWActuator::formatResponse(const QStringList &subtypes, const QHash<QString, QVariant> &attributes) const
{
    QJsonObject commands;
    QHash<QString, QVariant>::const_iterator i;
    for(i = attributes.begin(); i != attributes.end(); ++i){
        commands.insert(i.key(), QJsonValue::fromVariant(i.value()));
    }
    QJsonObject content;
    content.insert("subtypes", QJsonArray::fromStringList(subtypes));
    content.insert("commands", commands);
    QJsonObject jObject;
    jObject.insert("action", QJsonValue(QString("NOTIFY")));
    jObject.insert("content", content);
    return QString(QJsonDocument(jObject).toJson());
}
