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

#include "qwcontroller.h"

QWController::QWController(QObject *parent) : QObject(parent)
{
    setConfiguration(new QQWDeviceConfiguration);
}

QWController::~QWController()
{
    delete _configuration;
}


QQWDeviceConfiguration *QWController::configuration() const
{
    return _configuration;
}

void QWController::setConfiguration(QQWDeviceConfiguration *conf)
{
    _configuration = conf;
    _device = new QWCommanderDevice(_configuration->getConfiguration(), this);

    connect(_device, SIGNAL(updateAppliances(QStringList,QHash<QString,QVariant>)),
            this, SLOT(updateAppliances(QStringList,QHash<QString,QVariant>)));

    emit configurationChanged();
}


QQmlListProperty<QQWAppliance> QWController::appliances()
{
    return QQmlListProperty<QQWAppliance>(this, _appliances);
}


void QWController::updateAppliances(const QStringList &subtypes, const QHash<QString, QVariant> &values)
{
    foreach(QQWAppliance *app, _appliances){
        if(app->match(subtypes)){
            app->updateProperties(values);
        }
    }
}

void QWController::addAppliance(const QString &subtypes, const QHash<QString, QVariant> &values)
{
}
