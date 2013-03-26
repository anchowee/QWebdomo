#ifndef CONNECTEDDEVICE_H
#define CONNECTEDDEVICE_H

#include <QObject>
#include <QString>
#include <QList>
#include <QStringList>

#include "types.h"

class ConnectedDevice : public QObject
{
    Q_OBJECT
public:
    explicit ConnectedDevice(QObject *parent = 0);

    QString getAddress() const { return _address; }

    bool match(const QStringList &subtypes);
    virtual void send(const QByteArray &data) = 0;
    
signals:
    void queryRecived(QList<QString> subtypes, QHash<Commands, int> commands);
    void subtypesListRecived(QStringList subtypes);

private:
    QStringList _subtypes;
    QString _address;
    
};

#endif // CONNECTEDDEVICE_H
