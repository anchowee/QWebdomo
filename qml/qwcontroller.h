#ifndef QWCONTROLLER_H
#define QWCONTROLLER_H

#include "QWDevice.h"
#include "qqwdeviceconfiguration.h"
#include "

#include <QtDeclarative/qdeclarative.h>
#include <QObject>
#include <QQmlListProperty>

class QWController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QWController)
    Q_PROPERTY(QQmlListProperty<QWAppliance> appliances READ appliances NOTIFY appliancesChanged)//TODO: implements
    Q_PROPERTY(QQWDeviceConfiguration *configuration READ configuration WRITE setConfiguration NOTIFY configurationChanged)
public:
    QWController(QObject *parent = 0);
    ~QWController();

    QStringList appliances() const;

    //Configuration
    QWDeviceConfiguration *configuration() const;
    void setConfiguration(QWDeviceConfiguration *conf);

public slots:
    void get(QStringList subtypes);
    void put(QStringList subtypes);

private:
    QWDevice *_device;
    QQWDeviceConfiguration *_configuration;
};

QML_DECLARE_TYPE(QWController)

#endif // QWCONTROLLER_H

