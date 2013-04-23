#ifndef QWCONTROLLER_H
#define QWCONTROLLER_H

#include "../src/QWDevice.h"
#include "qqwdeviceconfiguration.h"

#include <QObject>
#include <QQmlListProperty>

class QWController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QWController)
    Q_PROPERTY(QQmlListProperty<QWAppliance> appliances READ appliances NOTIFY appliancesChanged)
    Q_PROPERTY(QQWDeviceConfiguration *configuration READ configuration WRITE setConfiguration NOTIFY configurationChanged)
public:
    QWController(QObject *parent = 0);
    ~QWController();

    //appliances
    QQmlListProperty<QWAppliance> appliances();

    //Configuration
    QQWDeviceConfiguration *configuration() const;
    void setConfiguration(QQWDeviceConfiguration *conf);

signals:
    void appliancesChanged();
    void configurationChanged();

public slots:


private:
    QWDevice *_device;
    QQWDeviceConfiguration *_configuration;
    QList<QWAppliance*> _appliances;
};

#endif // QWCONTROLLER_H

