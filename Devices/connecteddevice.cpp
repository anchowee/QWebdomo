#include "connecteddevice.h"

ConnectedDevice::ConnectedDevice(QObject *parent) :
    QObject(parent)
{
}

bool ConnectedDevice::match(const QStringList &subtypes){
    foreach(QString st, _subtypes){
        if(!subtypes.removeOne(st))
            return false;
    }
    return true;
}
