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

    connect(_device, SIGNAL(updateAppliances(QList<QQWAppliance*>)),
            this, SLOT(updateAppliances(QList<QQWAppliance*>));

    connect(_device, SIGNAL(setAppliances(QList<QQWAppliance*>)),
            this, SLOT(addAppliances(QList<QQWAppliance*>)));

    emit configurationChanged();
}


QQmlListProperty<QQWAppliance> QWController::appliances()
{
    return QQmlListProperty<QQWAppliance>(this, _appliances);
}


void QWController::updateAppliances(const QList<QQWAppliance *> &appList)
{
    QList<QQWAppliance *>::iterator internalIt;
    QList<QQWAppliance *>::const_iterator updatesIt;
    for(internalIt = _appliances.begin(); internalIt != _appliances.end(); ++internalIt){
        QQWAppliance *app = *internalIt;
        for(updatesIt = appList.constBegin(); updatesIt != appList.constEnd(); ++updatesIt){
            const QQWAppliance *changedApp = *updatesIt;
            if(*app == *changedApp){
                app->updateProperties(changedApp->propertiesList());
            }
        }
    }
    emit appliancesChanged();
}

void QWController::addAppliances(const QList<QQWAppliance *> &appList)
{
    _appliances.append(appList);
    emit appliancesChanged();
}
