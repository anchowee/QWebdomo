#include "xmppdevice.h"

XmppDevice::XmppDevice(QObject *parent, ConnectedDevice *parentDevice) :
    Device(parent, parentDevice)
{
    _client = new QXmppClient(this);
}
