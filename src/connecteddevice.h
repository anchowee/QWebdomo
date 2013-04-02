#ifndef CONNECTEDDEVICE_H
#define CONNECTEDDEVICE_H

#include "qwebdomo_global.h"

#include <QObject>
#include <QString>
#include <QList>
#include <QStringList>

class QWEBDOMOSHARED_EXPORT ConnectedDevice : public QObject
{
    Q_OBJECT
public:
    explicit ConnectedDevice(QObject *parent = 0);

    bool match(QStringList subtypes) const;
    virtual void send(const QByteArray &data) const = 0;
    
signals:
//    void queryRecived(QList<QString> subtypes, QHash<Commands, int> commands);
    void subtypesListRecived(QStringList subtypes);

private:
    QStringList _subtypes;
    
};

#endif // CONNECTEDDEVICE_H
