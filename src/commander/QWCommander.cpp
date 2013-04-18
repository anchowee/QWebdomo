#include "QWCommander.h"

QWCommander::QWCommander(const QWDeviceConfiguration &configuration, QObject *parent) :
    QWDevice(configuration, parent)
{
}

QStringList QWCommander::actuators() const
{
    return _actuators;
}
