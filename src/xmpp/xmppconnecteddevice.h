#ifndef XMPPCONNECTEDDEVICE_H
#define XMPPCONNECTEDDEVICE_H

#include "../qwebdomo_global.h"
#include "../connecteddevice.h"

class QWEBDOMOSHARED_EXPORT XmppConnectedDevice : public ConnectedDevice
{
    Q_OBJECT
public:
    explicit XmppConnectedDevice(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // XMPPCONNECTEDDEVICE_H
