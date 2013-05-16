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

#include "QWDevice.h"

#include <qxmpp/QXmppConfiguration.h>
#include <qxmpp/QXmppMessage.h>

#include <QHostInfo>
#include <QJsonDocument>
#include <QJsonObject>

class QWDevicePrivate {
public:
    QWDevicePrivate(const QWDeviceConfiguration &conf) :
        configuration(conf) {}

    QWDeviceConfiguration configuration;
    QXmppMucManager mucManager;
};

QWDevice::QWDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QXmppClient(parent), d(new QWDevicePrivate(configuration))
{
#ifdef QT_DEBUG
    logger()->setLoggingType(QXmppLogger::StdoutLogging);
#endif
    addExtension(&d->mucManager);
    QXmppConfiguration *conf = dynamic_cast<QXmppConfiguration*>(&d->configuration);
    connectToServer(*conf);

    connect(this, SIGNAL(connected()), this, SLOT(startChat()));
    connect(this, SIGNAL(messageReceived(QXmppMessage)), this, SLOT(_parseMessage(QXmppMessage)));
}

QWDevice::~QWDevice()
{
    delete d;
}

QString QWDevice::roomJid() const
{
    return d->configuration.roomJid();
}

void QWDevice::startChat()
{
#ifdef QT_DEBUG
    qDebug() << "starting chat";
#endif
    QXmppMucRoom *room = d->mucManager.addRoom(d->configuration.roomJid());
    room->setNickName(configuration().jid());
    room->join();

    connect(this, SIGNAL(sendRoomMessage(QString)), room, SLOT(sendMessage(QString)));
    connect(room, SIGNAL(participantAdded(QString)), this, SLOT(addDevice(QString)));
    connect(room, SIGNAL(messageReceived(QXmppMessage)), this, SLOT(_parseMessage(QXmppMessage)));
}

void QWDevice::addDevice(const QString &jid)
{
#ifdef QT_DEBUG
    qDebug() << "Adding new Device: " << jid;
#endif
}

void QWDevice::_parseMessage(const QXmppMessage &message)
{
    QJsonDocument doc = QJsonDocument::fromJson(message.body().toUtf8());
    QJsonObject obj = doc.object();
    QJsonValue action = obj.value("action");
    QString type = action.toString();
    QJsonValue content = obj.value("content");
    parseMessage(message.from(), type, content);
}
