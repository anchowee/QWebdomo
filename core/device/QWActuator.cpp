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

class QWActuatorPrivate {
public:
    explicit QWActuatorPrivate() :
        started(false) {}

    QList<QSharedPointer<QWAppliance> > appliances;
    QHash<QString, QVariant> globalVars;
    bool started;
};

QWActuator::QWActuator(QObject *parent) :
    QObject(parent), d(new QWActuatorPrivate)
{}



QWActuator::~QWActuator()
{
    delete d;
}

QStringList QWActuator::getSubtypes() const
{
    QStringList subtypes;
    for(int i = 0; i < d->appliances.length(); i++){
        subtypes.append(d->appliances.at(i)->subtypes());
        subtypes.append(d->appliances.at(i)->name());
    }
    return subtypes;
}

void QWActuator::setVars(const QHash<QString, QVariant> &vars)
{
    if(d->started) return;
    d->globalVars = vars;
}

QVariant QWActuator::var(const QString &name){
    return d->globalVars.value(name);
}

void QWActuator::put(const QStringList &subtypes, const QHash<QString, QVariant> &attributes)
{
    QList<QSharedPointer<QWAppliance> > appsToChange = find(subtypes);
    if(appsToChange.length() == 0) return;
    changeState(&appsToChange, attributes);
    const QString response = formatResponse("PUT", appsToChange);
    if(response != ""){
        emit notifyPut(response);
    }
}

void QWActuator::get(const QString &senderJid, const QStringList &subtypes, const QHash<QString, QVariant> &attributes)
{
    const QList<QSharedPointer<QWAppliance> > apps = find(subtypes, attributes);
    if(apps.length() == 0) return;
    const QString response = formatResponse("GET", apps);
    if(response != ""){
        emit notifyGet(senderJid, response);
    }
}

QString QWActuator::formatResponse(const QString &respType, const QList<QSharedPointer<QWAppliance> > &appliances) const
{
    // it returns an object like:
    // { action:"NOTIFY_GET", content:[{name: "example", subtypes: [], attributes:{k:v}}]}
#ifdef QT_DEBUG
    qDebug() << "formatting response";
#endif
    QJsonArray appliancesArray;
    QList<QSharedPointer<QWAppliance> >::const_iterator it;
    for(it = appliances.constBegin(); it != appliances.constEnd(); ++it){
        const QSharedPointer<QWAppliance> el = *it;
        QJsonObject app;

        QJsonObject attributes;
        QHash<QString, QVariant>::const_iterator hi;
        for(hi = el->attributes().constBegin(); hi != el->attributes().constEnd(); ++hi){
            attributes.insert(hi.key(), QJsonValue::fromVariant(hi.value()));
        }

        app.insert("name", QJsonValue(el->name()));
        app.insert("subtypes", QJsonArray::fromStringList(el->subtypes()));
        app.insert("attributes", attributes);
        appliancesArray.append(app);
    }

    QJsonObject response;
    response.insert("action", QJsonValue(QString("NOTIFY_%1").arg(respType)));
    response.insert("content", appliancesArray);
    return QString(QJsonDocument(response).toJson());
}


void QWActuator::addAppliance(const QSharedPointer<QWAppliance> app)
{
    if(!d->appliances.contains(app))
        d->appliances.append(app);
}

void QWActuator::initialize()
{
    ///By default it does nothing
}


void QWActuator::start()
{
    if(d->started) return;

    initialize();
    d->started = true;
}

bool QWActuator::isStarted()
{
    return d->started;
}

QList<QSharedPointer<QWAppliance> > QWActuator::find(const QStringList &subtypes, const QHash<QString, QVariant> &attributes)
{
#ifdef QT_DEBUG
    qDebug() << "Finding";
#endif
    QList<QSharedPointer<QWAppliance> > results = d->appliances;
    if(subtypes.length() != 0) {
        for(int i = results.length()-1; i >=0; i--){
            for(int j = 0; j < subtypes.length(); j++){
                QList<QString>::const_iterator it = qBinaryFind(results.at(i)->subtypes(), subtypes[j]);
                if(it == results.at(i)->subtypes().constEnd() && subtypes[j] != results.at(i)->name()){
                    results.removeAt(i);
                    break;
                }
            }
        }
    }

    const QStringList keys = attributes.keys();
    if(attributes.keys().length() != 0) {
        for(int i = results.length()-1; i >= 0; i--){
            for(int j = 0; j < keys.length(); j++){
                const QVariant r = results.at(i)->attributes().value(keys[j]);
                if(r != attributes.value(keys[j])){
                    results.removeAt(i);
                    break;
                }
            }
        }
    }

    return results;
}
