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

QWController::QWController(QObject *parent)
{
    _configuration = new QQWDeviceConfiguration;
    _device = new QWDevice(_configuration->getConfiguration(), this);
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
    _device = new QWDevice(_configuration->getConfiguration(), this);
    emit configurationChanged();
}


QQmlListProperty<QWAppliance> QWController::appliances()
{
    return QQmlListProperty<QWAppliance>(this, _appliances);
}
