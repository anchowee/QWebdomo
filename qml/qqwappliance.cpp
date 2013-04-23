#include "qqwappliance.h"

QQWAppliance::QQWAppliance(QObject *parent) :
    QObject(parent)
{
}


QQmlListProperty<QWAppProperty> QQWAppliance::properties()
{
    return QQmlListProperty<QWAppProperty>(this, _properties);
}

QString QQWAppliance::name() const
{
    return _name;
}

QStringList QQWAppliance::subtypes() const
{
    return _subtypes;
}
