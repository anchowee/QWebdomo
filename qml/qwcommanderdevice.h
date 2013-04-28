#ifndef QWCOMMANDERDEVICE_H
#define QWCOMMANDERDEVICE_H

#include "../src/QWDevice.h"

#include <QJsonValue>

class QWCommanderDevice : public QWDevice
{
    Q_OBJECT
public:
    explicit QWCommanderDevice(const QWDeviceConfiguration &configuration, QObject *parent = 0);

public slots:
    void inspectAppliances();

signals:
    void updateAppliances(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void setAppliances(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    
protected:
    void parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content);
};

#endif // QWCOMMANDERDEVICE_H
