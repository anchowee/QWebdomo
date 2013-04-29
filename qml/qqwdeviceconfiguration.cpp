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
    QObject(parent), QWDeviceConfiguration()
{
}

QQWDeviceConfiguration::SecurityMode QQWDeviceConfiguration::_streamSecurityMode() const
{
    return (int)streamSecurityMode();
}

QString QQWDeviceConfiguration::userName() const
{
    return user();
}

void QQWDeviceConfiguration::setUserName(const QString &name)
{
    setUser(name);
}

QString QQWDeviceConfiguration::roomName() const
{
    return applianceSetRoomName();
}

void QQWDeviceConfiguration::setRoomName(const QString &rn)
{
    setApplianceSetRoomName(rn);
}

QString QQWDeviceConfiguration::serviceName() const
{
    return applianceSetServiceName();
}

void QQWDeviceConfiguration::setServiceName(const QString &sn)
{
    setApplianceSetServiceName(sn);
}

QWDeviceConfiguration QQWDeviceConfiguration::getConfiguration() const
{
    return *(dynamic_cast<const QWDeviceConfiguration*>(this));
}


void QQWDeviceConfiguration::_setStreamSecurityMode(int mode)
{
    setStreamSecurityMode((int)mode);
}
