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

#ifndef QQWDEVICECONFIGURATION_H
#define QQWDEVICECONFIGURATION_H

#include "QWDeviceConfiguration.h"

#include <QObject>

class QQWDeviceConfiguration : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QQWDeviceConfiguration)
    Q_ENUMS(QWDeviceConfiguration::StreamSecurityMode)
    Q_PROPERTY(QWDeviceConfiguration::StreamSecurityMode streamSecurityMode READ streamSecurityMode WRITE setStreamSecurityMode)
    Q_PROPERTY(QString userName READ userName WRITE setUserName)
    Q_PROPERTY(QString password READ password WRITE setPassword)
    Q_PROPERTY(QString domain READ domain WRITE setDomain)
    Q_PROPERTY(QString roomName READ roomName WRITE setRoomName)
    Q_PROPERTY(QString serviceName READ serviceName WRITE setServiceName)
    Q_PROPERTY(QString roomJid READ roomJid)
public:
    explicit QQWDeviceConfiguration(QObject *parent = 0);

    //StreamSecurityMode
    QWDeviceConfiguration::StreamSecurityMode streamSecurityMode() const;
    void setStreamSecurityMode(QWDeviceConfiguration::StreamSecurityMode mode);

    //Username
    QString userName() const;
    void setUserName(const QString &name);

    //Password
    QString password() const;
    void setPassword(const QString &pw);

    //Domain
    QString domain() const;
    void setDomain(const QString &d);

    //RoomName
    QString roomName() const;
    void setRoomName(const QString &rn);

    //ServiceName
    QString serviceName() const;
    void setServiceName(const QString &sn);

    //RoomJid
    QString roomJid() const;

    //conf
    QWDeviceConfiguration getConfiguration() const;

private:
    QWDeviceConfiguration *_conf;
    
};

//QML_DECLARE_TYPE(QQWDeviceConfiguration)

#endif // QQWDEVICECONFIGURATION_H
