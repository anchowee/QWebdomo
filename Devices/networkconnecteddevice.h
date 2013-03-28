#ifndef NETWORKCONNECTEDDEVICE_H
#define NETWORKCONNECTEDDEVICE_H

#include <QHostAddress>
#include <QTcpSocket>

#include "connecteddevice.h"
#include "../Utils/threadedtcpserver.h"

class NetworkConnectedDevice : public ConnectedDevice
{
    Q_OBJECT
public:
    explicit NetworkConnectedDevice(QHostAddress address, QObject *parent = 0);

    void send(const QByteArray &data);

private:
    QTcpSocket *_sendSocket;
    ThreadedTcpServer *_tcpServer;

};

#endif // NETWORKCONNECTEDDEVICE_H
