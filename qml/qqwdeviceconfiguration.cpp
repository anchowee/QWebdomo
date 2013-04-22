#include "qqwdeviceconfiguration.h"

QQWDeviceConfiguration::QQWDeviceConfiguration(QObject *parent) :
    QObject(parent)
{
    _conf = new QWDeviceConfiguration;
}

QString QQWDeviceConfiguration::userName() const
{
    return _conf->user();
}

void QQWDeviceConfiguration::setUserName(const QString &name)
{
    _conf->setUser(name);
}

QString QQWDeviceConfiguration::password() const
{
    return _conf->password();
}

void QQWDeviceConfiguration::setPassword(const QString &pw)
{
    _conf->setPassword(pw);
}

QString QQWDeviceConfiguration::domain() const
{
    return _conf->domain();
}

void QQWDeviceConfiguration::setDomain(const QString &d)
{
    _conf->setDomain(d);
}

QString QQWDeviceConfiguration::roomName() const
{
    return _conf->applianceSetRoomName();
}

void QQWDeviceConfiguration::setRoomName(const QString &rn)
{
    _conf->setApplianceSetRoomName(rn);
}

QString QQWDeviceConfiguration::serviceName() const
{
    return _conf->applianceSetServiceName();
}

void QQWDeviceConfiguration::setServiceName(const QString &sn)
{
    _conf->setApplianceSetServiceName(sn);
}

QString QQWDeviceConfiguration::roomJid() const
{
    return _conf->roomJid();
}

QWDeviceConfiguration QQWDeviceConfiguration::getConfiguration() const
{
    return *_conf;
}
