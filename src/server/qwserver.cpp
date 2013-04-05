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
