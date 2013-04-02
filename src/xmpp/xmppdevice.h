#ifndef XMPPDEVICE_H
#define XMPPDEVICE_H

#include "../qwebdomo_global.h"
#include "../device.h"

#include <qxmpp/QXmppClient.h>

class QWEBDOMOSHARED_EXPORT XmppDevice : public Device
{
    Q_OBJECT
public:
    explicit XmppDevice(QObject *parent = 0, , ConnectedDevice *parentDevice = 0);
    
signals:
    
public slots:

private:
    QXmppClient *_client;
    
};

#endif // XMPPDEVICE_H
