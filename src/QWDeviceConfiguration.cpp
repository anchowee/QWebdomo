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

#include "QWDeviceConfiguration.h"

class QWDeviceConfigurationPrivate : public QSharedData
{
public:
    QWDeviceConfigurationPrivate() :
        applianceSetServiceName("appset"),
        applianceSetRoomName("local_appliances") {}

    QWDeviceConfigurationPrivate(const QWDeviceConfigurationPrivate &other) :
        QSharedData(other),
        applianceSetServiceName(other.applianceSetServiceName),
        applianceSetRoomName(other.applianceSetRoomName) {}

    // The name of the group chat room subdomain
    QString applianceSetServiceName;

    // The name of the muc chat room
    QString applianceSetRoomName;
};

QWDeviceConfiguration::QWDeviceConfiguration() :
    d(new QWDeviceConfigurationPrivate)
{
}

QWDeviceConfiguration::QWDeviceConfiguration(const QWDeviceConfiguration &other) :
    QXmppConfiguration(other), d(other.d)
{}

QWDeviceConfiguration::~QWDeviceConfiguration()
{
}


void QWDeviceConfiguration::setApplianceSetServiceName(const QString &serviceName)
{
    d->applianceSetServiceName = serviceName;
}

void QWDeviceConfiguration::setApplianceSetRoomName(const QString &roomName)
{
    d->applianceSetRoomName = roomName;
}

QString QWDeviceConfiguration::applianceSetServiceName() const
{
    return d->applianceSetServiceName;
}

QString QWDeviceConfiguration::applianceSetRoomName() const
{
    return d->applianceSetRoomName;
}

QString QWDeviceConfiguration::roomJid() const
{
    return d->applianceSetRoomName+"@"+d->applianceSetServiceName+"."+domain();
}
