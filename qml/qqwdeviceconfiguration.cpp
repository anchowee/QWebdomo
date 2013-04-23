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

#include "qqwdeviceconfiguration.h"

QQWDeviceConfiguration::QQWDeviceConfiguration(QObject *parent) :
    QObject(parent)
{
    _conf = new QWDeviceConfiguration;
}

QString QQWDeviceConfiguration::userName() const
{
    return _conf->user();
}

void QQWDeviceConfiguration::setUserName(const QString &name)
{
    _conf->setUser(name);
}

QString QQWDeviceConfiguration::password() const
{
    return _conf->password();
}

void QQWDeviceConfiguration::setPassword(const QString &pw)
{
    _conf->setPassword(pw);
}

QString QQWDeviceConfiguration::domain() const
{
    return _conf->domain();
}

void QQWDeviceConfiguration::setDomain(const QString &d)
{
    _conf->setDomain(d);
}

QString QQWDeviceConfiguration::roomName() const
{
    return _conf->applianceSetRoomName();
}

void QQWDeviceConfiguration::setRoomName(const QString &rn)
{
    _conf->setApplianceSetRoomName(rn);
}

QString QQWDeviceConfiguration::serviceName() const
{
    return _conf->applianceSetServiceName();
}

void QQWDeviceConfiguration::setServiceName(const QString &sn)
{
    _conf->setApplianceSetServiceName(sn);
}

QString QQWDeviceConfiguration::roomJid() const
{
    return _conf->roomJid();
}

QWDeviceConfiguration QQWDeviceConfiguration::getConfiguration() const
{
    return *_conf;
}
