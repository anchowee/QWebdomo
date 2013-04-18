#ifndef QWCOMMANDER_H
#define QWCOMMANDER_H

#include "qwebdomo_global.h"
#include "QWDevice.h"

#include <QStringList>

class QWEBDOMOSHARED_EXPORT QWCommander : public QWDevice
{
    Q_OBJECT
    Q_PROPERTY(QStringList actuators READ actuators NOTIFY actuatorsChanged)
public:
    explicit QWCommander(const QWDeviceConfiguration &configuration, QObject *parent = 0);
    
    QStringList actuators() const;

signals:
    void actuatorsChanged();
    
private:
    QStringList _actuators;
    
};

#endif // QWCOMMANDER_H
