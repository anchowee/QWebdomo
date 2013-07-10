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

#ifndef QWSERVER_H
#define QWSERVER_H

#include "qwebdomo_global.h"

#include <qxmpp/QXmppServer.h>
#include <qxmpp/QXmppPasswordChecker.h>
#include <qxmpp/QXmppPasswordChecker.h>

class QWEBDOMOSHARED_EXPORT QWServer : public QXmppServer
{
    Q_OBJECT
public:
    explicit QWServer(const QString &domain, QObject *parent = 0);
    
private:
    QString _name;
};

class PasswordChecker : public QXmppPasswordChecker
{
public:
    QXmppPasswordReply::Error getPassword(const QXmppPasswordRequest &request, QString &password){
        return QXmppPasswordReply::NoError;
        //TODO: implement
    }

    bool hasGetPassword() const { return true; }
};

#endif // QWSERVER_H
