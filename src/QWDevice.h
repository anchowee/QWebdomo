#ifndef DEVICE_H
#define DEVICE_H

#include "qwebdomo_global.h"
#include "QWDeviceConfiguration.h"
#include "QWActuator.h"

#include <qxmpp/QXmppClient.h>
#include <qxmpp/QXmppMucManager.h>

#include <QObject>
#include <QList>
#include <QHash>
#include <QStringList>

class QWEBDOMOSHARED_EXPORT QWDevice : public QXmppClient
{
    Q_OBJECT
public:
    explicit QWDevice(const QWDeviceConfiguration &configuration, QObject *parent = 0);
    ~QWDevice();

    void addActuator(const QWActuator &actuator);

public slots:
    void executeQuery(const QStringList &subtypes, const QHash<QString, QVariant> &commands);

private slots:
    void startChat();
    void addDevice(const QString &jid);
    void parseMessage(const QXmppMessage &message);

private:
    QHash<QString, QSharedPointer<const QWActuator> > *_actuators;
    QWDeviceConfiguration _configuration;
    QXmppMucManager *_mucManager;
    QXmppMucRoom *_room;
};

#endif // DEVICE_H
