#ifndef QWSERVER_H
#define QWSERVER_H

#include "qwebdomo_global.h"
#include "bonjourserviceregister.h"

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
    BonjourServiceRegister *_avahiPublisher;
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
