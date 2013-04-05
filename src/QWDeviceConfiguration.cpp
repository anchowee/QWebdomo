#include "QWDeviceConfiguration.h"

class QWDeviceConfigurationPrivate : public QSharedData
{
public:
    QWDeviceConfigurationPrivate() :
        applianceSetServiceName("appset"),
        applianceSetRoomName("local_appliances") {}

    QWDeviceConfigurationPrivate(const QWDeviceConfigurationPrivate &other) :
        QSharedData(other),
        applianceSetServiceName(other.applianceSetServiceName),
        applianceSetRoomName(other.applianceSetRoomName) {}

    // The name of the group chat room subdomain
    QString applianceSetServiceName;

    // The name of the muc chat room
    QString applianceSetRoomName;
};

QWDeviceConfiguration::QWDeviceConfiguration() :
    d(new QWDeviceConfigurationPrivate)
{
}

QWDeviceConfiguration::QWDeviceConfiguration(const QWDeviceConfiguration &other) :
    QXmppConfiguration(other), d(other.d)
{}

QWDeviceConfiguration::~QWDeviceConfiguration()
{
}


void QWDeviceConfiguration::setApplianceSetServiceName(const QString &serviceName)
{
    d->applianceSetServiceName = serviceName;
}

void QWDeviceConfiguration::setApplianceSetRoomName(const QString &roomName)
{
    d->applianceSetRoomName = roomName;
}

QString QWDeviceConfiguration::applianceSetServiceName() const
{
    return d->applianceSetServiceName;
}

QString QWDeviceConfiguration::applianceSetRoomName() const
{
    return d->applianceSetRoomName;
}

QString QWDeviceConfiguration::roomJid() const
{
    return d->applianceSetRoomName+"@"+d->applianceSetServiceName+"."+domain();
}
