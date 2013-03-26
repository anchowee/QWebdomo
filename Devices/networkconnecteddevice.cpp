#include "networkconnecteddevice.h"

NetworkConnectedDevice::NetworkConnectedDevice(QObject *parent) :
    ConnectedDevice(parent)
{
    //TODO: setup network
}

void NetworkConnectedDevice::send(const QByteArray &data){
    //TODO: send data through network
}
