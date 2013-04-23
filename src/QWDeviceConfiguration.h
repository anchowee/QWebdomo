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

#ifndef QWDEVICECONFIGURATION_H
#define QWDEVICECONFIGURATION_H

#include "qwebdomo_global.h"

#include <qxmpp/QXmppConfiguration.h>

#include <QSharedDataPointer>

class QWDeviceConfigurationPrivate;

class QWEBDOMOSHARED_EXPORT QWDeviceConfiguration : public QXmppConfiguration
{
public:
    QWDeviceConfiguration();
    QWDeviceConfiguration(const QWDeviceConfiguration &other);
    ~QWDeviceConfiguration();

    //Setters
    void setApplianceSetServiceName(const QString &serviceName);
    void setApplianceSetRoomName(const QString &roomName);

    //Getters
    QString applianceSetServiceName() const;
    QString applianceSetRoomName() const;
    QString roomJid() const;

private:
    QSharedDataPointer<QWDeviceConfigurationPrivate> d;
    
};

#endif // QWDEVICECONFIGURATION_H
