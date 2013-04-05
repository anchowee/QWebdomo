#ifndef DEVICE_H
#define DEVICE_H

#include "qwebdomo_global.h"
#include "QWDeviceConfiguration.h"
//#include "actuator.h"

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
    
public slots:
    //void parseQuery(const QStringList &subtypes, const QHash<Commands, int> &commands);

private slots:
    void startChat();

private:
    //QList<Actuator*> *_actuators; //TODO: arrays of actuators
    QWDeviceConfiguration _configuration;
    QXmppMucManager *_mucManager;
    QXmppMucRoom *_room;
};

#endif // DEVICE_H
