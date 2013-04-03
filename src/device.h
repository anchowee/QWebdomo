#ifndef DEVICE_H
#define DEVICE_H

#include "qwebdomo_global.h"
#include "actuator.h"

#include <qxmpp/QXmppClient.h>
#include <qxmpp/QXmppMucManager.h>

#include <QObject>
#include <QList>
#include <QHash>
#include <QStringList>

class QWEBDOMOSHARED_EXPORT Device : public QXmppClient
{
    Q_OBJECT
public:
    explicit Device(QObject *parent = 0);
    
public slots:
    void parseQuery(const QStringList &subtypes, const QHash<Commands, int> &commands);

private:
    QList<Actuator*> *_actuators; //TODO: arrays of actuators
    QXmppMucManager *_mucManager;
};

#endif // DEVICE_H
