#include "device.h"

Device::Device(QObject *parent) :
    QObject(parent), _parent(parentDevice)
{
    connect(_parent, SIGNAL(queryRecived(QList<QString>,QHash<Commands,int>)), this, SLOT(parseQuery(QStringList,QHash<Commands,int>)));
}

void Device::addChild(ConnectedDevice *child){
    _childs->push_back(child);
}

void Device::parseQuery(const QStringList &subtypes, const QHash<Commands, int> &commands){
    foreach (ConnectedDevice *dev, *_childs) {
        if(dev->match(subtypes)){
            sendTo(*dev, subtypes, commands);
        }
    }
}

void Device::sendTo(const ConnectedDevice &child, const QStringList &subtypes, const QHash<Commands, int> &commands){
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << quint16(0);
    out << qint8(0) << subtypes << commands;
    out.device()->seek(0);
    out << qint16(data.size() - sizeof(qint16));
    child.send(data);
}
