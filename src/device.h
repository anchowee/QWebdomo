#ifndef DEVICE_H
#define DEVICE_H

#include "qwebdomo_global.h"
#include "actuator.h"
#include "connecteddevice.h"

#include <QObject>
#include <QList>
#include <QHash>
#include <QStringList>

class QWEBDOMOSHARED_EXPORT Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(QObject *parent = 0, ConnectedDevice *parentDevice = 0);

    void addChild(ConnectedDevice *child);
    void removeChild(const ConnectedDevice &child);
    
public slots:
    void parseQuery(const QStringList &subtypes, const QHash<Commands, int> &commands);

private:
    void sendTo(const ConnectedDevice &child, const QStringList &subtypes, const QHash<Commands, int> &commands);

private:
    QList<Actuator*> *_actuators; //TODO: arrays of actuators
    QList<ConnectedDevice*> *_childs; //TODO: maybe a QMap is better for searches
    ConnectedDevice *_parent;
    
};

#endif // DEVICE_H
