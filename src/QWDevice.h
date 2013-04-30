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

#ifndef DEVICE_H
#define DEVICE_H

#include "qwebdomo_global.h"
#include "QWDeviceConfiguration.h"

#include <qxmpp/QXmppClient.h>
#include <qxmpp/QXmppMucManager.h>

#include <QHash>
#include <QStringList>
#include <QJsonValue>

class QWDevicePrivate;

class QWEBDOMOSHARED_EXPORT QWDevice : public QXmppClient
{
    Q_OBJECT
public:
    explicit QWDevice(const QWDeviceConfiguration &configuration, QObject *parent = 0);
    ~QWDevice();

    QString roomJid() const;

signals:
    void sendRoomMessage(const QString &message);

protected:
    virtual void parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content) = 0;

private slots:
    void startChat();
    void addDevice(const QString &jid);
    void _parseMessage(const QXmppMessage &message);

private:
    QWDevicePrivate *d;

};

#endif // DEVICE_H
