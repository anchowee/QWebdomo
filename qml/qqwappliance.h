#ifndef QQWAPPLIANCE_H
#define QQWAPPLIANCE_H

#include "QWAppliance.h"
#include "qwappproperty.h"

#include <QObject>
#include <QQmlListProperty>

class QQWAppliance : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QStringList subtypes READ subtypes)
    Q_PROPERTY(QQmlListProperty<QWAppProperty> properties READ properties)
public:
    explicit QQWAppliance(QObject *parent = 0);

    void setSubtypes(const QStringList &subtypes);

    //properties
    QQmlListProperty<QWAppProperty> properties();
    
signals:
    
public slots:

private:
    QStringList *_subtypes;

};

#endif // QQWAPPLIANCE_H
