#ifndef NETWORKCONNECTEDDEVICE_H
#define NETWORKCONNECTEDDEVICE_H

#import "connecteddevice.h"

class NetworkConnectedDevice : public ConnectedDevice
{
    Q_OBJECT
public:
    explicit NetworkConnectedDevice(QObject *parent = 0);

    void send(const QByteArray &data);

};

#endif // NETWORKCONNECTEDDEVICE_H
