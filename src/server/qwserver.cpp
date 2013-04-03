#include "qwserver.h"
#include <QHostInfo>

QWServer::QWServer(QString name, QObject *parent) :
    QXmppServer(parent), _name(name)
{
    setPasswordChecker(new PasswordChecker);
    listenForClients();
    listenForServers();
    _avahiPublisher = new QAvahiServicePublisher(this);
    _avahiPublisher->publish(QHostInfo::localHostName(), "_xmpp-server._tcp", 5269, "Webdomo XMPP local server");
}
