#include "qwserver.h"
#include "bonjourrecord.h"

#include <QHostInfo>

QWServer::QWServer(const QString &domain, QObject *parent) :
    QXmppServer(parent)
{
    setDomain(domain);
    setPasswordChecker(new PasswordChecker);
    listenForClients();
    listenForServers();
    _avahiPublisher = new BonjourServiceRegister(this);
    _avahiPublisher->registerService(BonjourRecord(QHostInfo::localHostName(), "_xmpp-server._tcp", "local"), 5269);
}
