#ifndef QWCOMMANDERDEVICE_H
#define QWCOMMANDERDEVICE_H

#include "../src/QWDevice.h"

class QWCommanderDevice : public QWDevice
{
    Q_OBJECT
public:
    explicit QWCommanderDevice(const QWDeviceConfiguration &configuration, QObject *parent = 0);

signals:
    void updateAppliances(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    
protected:
    void parseMessage(const QString &type, const QJsonValue &content);
};

#endif // QWCOMMANDERDEVICE_H
