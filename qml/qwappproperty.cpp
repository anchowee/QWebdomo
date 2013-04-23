#include "qwappproperty.h"

QWAppProperty::QWAppProperty(QObject *parent) :
    QObject(parent)
{
}

QString QWAppProperty::name() const
{
    return _name;
}

void QWAppProperty::setName(const QString &name)
{
    _name = name;
}

QVariant QWAppProperty::value() const
{
    return _value;
}

void QWAppProperty::setValue(const QVariant &value)
{
    _value = value;
}
