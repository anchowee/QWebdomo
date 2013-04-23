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

#ifndef QWPARSER_H
#define QWPARSER_H

#include "qwebdomo_global.h"

#include <QObject>
#include <QJsonValue>
#include <QStringList>
#include <QHash>
#include <QVariant>

class QWEBDOMOSHARED_EXPORT QWParser : public QObject
{
    Q_OBJECT
    Q_ENUMS(MessageType)
public:

    enum MessageType {
        GetMessage,
        PutMessage,
        QueryMessage
    };

    explicit QWParser(QObject *parent = 0);
    
signals:
    void sendMessage(const QString &bareJid, const QString &message);
    void doPut(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void doGet(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void notify(const QString &message);
    
public slots:
    virtual void parse(const QString &bareJid, MessageType type, const QJsonValue &content) = 0;
};

#endif // QWPARSER_H
