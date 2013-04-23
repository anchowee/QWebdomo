#ifndef DEVICE_H
#define DEVICE_H

#include "qwebdomo_global.h"
#include "QWDeviceConfiguration.h"
#include "QWActuator.h"
#include "QWParser.h"

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

    enum QueryType{
        Get,
        Put
    };

    explicit QWDevice(const QWDeviceConfiguration &configuration, QObject *parent = 0);
    ~QWDevice();

    void addActuator(const QWActuator &actuator);

    void addParser(QWParser *parser);
    void removeParser(QWParser *parser);
    QString roomJid() const;

signals:
    void notify(const QString &message);

public slots:
    void doGet(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void doPut(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void executeQuery(QueryType type, const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void sendMessage(const QString &bareJid, const QString &message);
    void sendMessage(const QString &bareJid, QWParser::MessageType action, const QJsonValue &content);

private slots:
    void startChat();
    void addDevice(const QString &jid);
    void parseMessage(const QXmppMessage &message);

private:
    QWDevicePrivate *d;

};

#endif // DEVICE_H
