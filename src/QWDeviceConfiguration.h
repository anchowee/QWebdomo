#ifndef QWDEVICECONFIGURATION_H
#define QWDEVICECONFIGURATION_H

#include "qwebdomo_global.h"

#include <qxmpp/QXmppConfiguration.h>

#include <QSharedDataPointer>

class QWDeviceConfigurationPrivate;

class QWEBDOMOSHARED_EXPORT QWDeviceConfiguration : public QXmppConfiguration
{
public:
    QWDeviceConfiguration();
    QWDeviceConfiguration(const QWDeviceConfiguration &other);
    ~QWDeviceConfiguration();

    //Setters
    void setApplianceSetServiceName(const QString &serviceName);
    void setApplianceSetRoomName(const QString &roomName);

    //Getters
    QString applianceSetServiceName() const;
    QString applianceSetRoomName() const;
    QString roomJid() const;

private:
    QSharedDataPointer<QWDeviceConfigurationPrivate> d;
    
};

#endif // QWDEVICECONFIGURATION_H
