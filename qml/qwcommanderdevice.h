#ifndef QWCOMMANDERDEVICE_H
#define QWCOMMANDERDEVICE_H

#include "qqwappliance.h"
#include "QWDevice.h"

#include <QJsonValue>

class QWCommanderDevice : public QWDevice
{
    Q_OBJECT
public:
    explicit QWCommanderDevice(const QWDeviceConfiguration &configuration, QObject *parent = 0);

public slots:
    void getAll(const QString &deviceJid = QString());
    void changeAppliancesProperties(const QStringList &subtypes, const QHash<QString, QVariant> &values);

signals:
    void updateAppliances(const QString &senderJid, const QList<QQWAppliance *> &appList);
    void setAppliances(const QString &senderJid, const QList<QQWAppliance *> &appList);
    
protected:
    void composeAndSendRequest(const QString &type, const QStringList &subtypes, const QHash<QString, QVariant> &properties);
    void parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content);
};

#endif // QWCOMMANDERDEVICE_H
