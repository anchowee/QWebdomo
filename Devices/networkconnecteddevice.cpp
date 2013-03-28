#include "networkconnecteddevice.h"

NetworkConnectedDevice::NetworkConnectedDevice(QHostAddress address, QObject *parent) :
    ConnectedDevice(parent)
{
    _sendSocket = new QTcpSocket(this);
    _sendSocket->connectToHost(address, 8787, QTcpSocket::ReadOnly);

    _tcpServer = new ThreadedTcpServer(this);
    //TODO: setup network
}

void NetworkConnectedDevice::send(const QByteArray &data){
    //TODO: send data through network
}
