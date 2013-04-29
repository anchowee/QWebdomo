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
    void inspectAppliances();

signals:
    void updateAppliances(const QList<QQWAppliance *> &appList);
    void setAppliances(const QList<QQWAppliance *> &appList);
    
protected:
    void parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content);
};

#endif // QWCOMMANDERDEVICE_H
