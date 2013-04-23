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

#include "qwserver.h"
#include "bonjourrecord.h"

#ifdef QT_DEBUG
#include <qxmpp/QXmppLogger.h>
#endif

#include <QHostInfo>

QWServer::QWServer(const QString &domain, QObject *parent) :
    QXmppServer(parent)
{
#ifdef QT_DEBUG
    QXmppLogger log;
    log.setLoggingType(QXmppLogger::StdoutLogging);
    setLogger(&log);
#endif
    PasswordChecker passChecker;
    setDomain(domain);
    setPasswordChecker(&passChecker);
    listenForClients();
    listenForServers();
    _avahiPublisher = new BonjourServiceRegister(this);
    _avahiPublisher->registerService(BonjourRecord(QHostInfo::localHostName(), "_xmpp-server._tcp", "local"), 5269);
}
