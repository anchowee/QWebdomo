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

#ifdef QT_DEBUG
#include <QDebug>
#endif

QWActuator::QWActuator(QObject *parent) :
    QObject(parent)
{
#ifdef QT_DEBUG
    qDebug() << "Creating new actuator";
#endif
    _appliances = new QList<QWAppliance>();
}

QWActuator::~QWActuator()
{
    delete _appliances;
}

QStringList QWActuator::getSubtypes() const
{
    QStringList subtypes;
    for(int i = 0; i < _appliances->length(); i++){
        subtypes.append(_appliances->at(i).subtypes());
        subtypes.append(_appliances->at(i).name());
    }
    return subtypes;
}

QString QWActuator::getAll() const
{
    return formatResponse("GET", *_appliances);
}

QString QWActuator::doGet(QStringList &subtypes, QHash<QString, QVariant> &attributes)
{
    return formatResponse("GET", get(subtypes, attributes));
}

QString QWActuator::doPut(QStringList &subtypes, QHash<QString, QVariant> &attributes)
{
    return formatResponse("PUT", put(subtypes, attributes));
}

QString QWActuator::formatResponse(const QString &respType, const QList<QWAppliance> &appliances) const
{
    // it returns an object like:
    // { action:"NOTIFY_GET", content:[{name: "example", subtypes: [], attributes:{k:v}}]}
#ifdef QT_DEBUG
    qDebug() << "formatting response";
#endif
    QJsonArray appliancesArray;
    QList<QWAppliance>::const_iterator it;
    for(it = appliances.constBegin(); it != appliances.constEnd(); ++it){
        const QWAppliance el = *it;
        QJsonObject app;

        QJsonObject attributes;
        QHash<QString, QVariant>::const_iterator hi;
        for(hi = el.attributes().constBegin(); hi != el.attributes().constEnd(); ++hi){
            attributes.insert(hi.key(), QJsonValue::fromVariant(hi.value()));
        }

        app.insert("name", QJsonValue(el.name()));
        app.insert("subtypes", QJsonArray::fromStringList(el.subtypes()));
        app.insert("attributes", attributes);
        appliancesArray.append(app);
    }

    QJsonObject response;
    response.insert("action", QJsonValue(QString("NOTIFY_%1").arg(respType)));
    response.insert("content", appliancesArray);
    return QString(QJsonDocument(response).toJson());
}


void QWActuator::addAppliance(const QWAppliance &app)
{
    if(!_appliances->contains(app))
#ifdef QT_DEBUG
    qDebug() << "adding appliance";
#endif
        _appliances->append(app);
}

QList<QWAppliance> QWActuator::find(QStringList &subtypes)
{
#ifdef QT_DEBUG
    qDebug() << "Finding; subtypes length: " << subtypes.length();
    for(int i = 0; i < subtypes.length(); ++i){
        qDebug() << subtypes.at(i);
    }
#endif
    QList<QWAppliance> results;
    if(subtypes.length() == 0) return results;

    results.append(*_appliances);
    subtypes.sort();
    QList<QWAppliance>::const_iterator it;
    for(it = _appliances->constBegin(); it != _appliances->constEnd(); ++it){
        const QWAppliance app = *it;
        int y = 0;
        for(int i = 0; i < subtypes.length(); i++){
            y = app.subtypes().indexOf(subtypes.at(i), y);
            if(y == -1 ){
                results.removeAll(app);
            }
        }
    }
    return results;
}
