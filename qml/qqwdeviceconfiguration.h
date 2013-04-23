#ifndef QQWDEVICECONFIGURATION_H
#define QQWDEVICECONFIGURATION_H

#include "../src/QWDeviceConfiguration.h"

#include <QObject>

class QQWDeviceConfiguration : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QQWDeviceConfiguration)
    Q_PROPERTY(QString userName READ userName WRITE setUserName)
    Q_PROPERTY(QString password READ password WRITE setPassword)
    Q_PROPERTY(QString domain READ domain WRITE setDomain)
    Q_PROPERTY(QString roomName READ roomName WRITE setRoomName)
    Q_PROPERTY(QString serviceName READ serviceName WRITE setServiceName)
    Q_PROPERTY(QString roomJid READ roomJid)
public:
    explicit QQWDeviceConfiguration(QObject *parent = 0);

    //Username
    QString userName() const;
    void setUserName(const QString &name);

    //Password
    QString password() const;
    void setPassword(const QString &pw);

    //Domain
    QString domain() const;
    void setDomain(const QString &d);

    //RoomName
    QString roomName() const;
    void setRoomName(const QString &rn);

    //ServiceName
    QString serviceName() const;
    void setServiceName(const QString &sn);

    //RoomJid
    QString roomJid() const;

    //conf
    QWDeviceConfiguration getConfiguration() const;

private:
    QWDeviceConfiguration *_conf;
    
};

//QML_DECLARE_TYPE(QQWDeviceConfiguration)

#endif // QQWDEVICECONFIGURATION_H
