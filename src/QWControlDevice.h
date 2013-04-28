#ifndef QWCONTROLDEVICE_H
#define QWCONTROLDEVICE_H

#include "qwebdomo_global.h"
#include "QWDevice.h"
#include "QWActuator.h"

class QWControlDevicePrivate;

class QWEBDOMOSHARED_EXPORT QWControlDevice : public QWDevice
{
    Q_OBJECT
public:
    explicit QWControlDevice(const QWDeviceConfiguration &configuration, QObject *parent = 0);
    ~QWControlDevice();

    void addActuator(const QWActuator &actuator);
    
signals:

protected:
    void parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content);

private:
    QWControlDevicePrivate *d;
    
};

#endif // QWCONTROLDEVICE_H
