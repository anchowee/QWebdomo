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
    Q_ENUMS(ActionType)
public:

    explicit QWDevice(const QWDeviceConfiguration &configuration, QObject *parent = 0);
    ~QWDevice();

    void addActuator(const QWActuator &actuator);

public slots:
    void executeQuery(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void sendMessage(const QString &bareJid, const QString &message);
    void sendMessage(const QString &bareJid, QWParser::ParserType action, const QJsonValue &content);

private slots:
    void startChat();
    void addDevice(const QString &jid);
    void parseMessage(const QXmppMessage &message);

private:
    QWDevicePrivate *d;

};

#endif // DEVICE_H
