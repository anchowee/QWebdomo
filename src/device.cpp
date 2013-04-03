#include "device.h"

Device::Device(QObject *parent) :
    QXmppClient(parent)
{
    _mucManager = new QXmppMucManager;
    addExtension(_mucManager);
}

void Device::parseQuery(const QStringList &subtypes, const QHash<Commands, int> &commands)
{
}
