#include "QWAppliance.h"

class QWAppliancePrivate : public QSharedData {
public:
    QWAppliancePrivate(){}

    QWAppliancePrivate(const QWAppliancePrivate &other) :
        QSharedData(other) {}

    QString name;
    QStringList subtypes;

    QHash<QString, QVariant> attributes;
};

QWAppliance::QWAppliance() :
    d(new QWAppliancePrivate)
{
}

QWAppliance::QWAppliance(const QWAppliance &other) :
    d(other.d)
{
}

QWAppliance::~QWAppliance()
{
}


void QWAppliance::setName(const QString &name)
{
    d->name = name;
}

QString QWAppliance::name() const
{
    return d->name;
}

void QWAppliance::setSubtypes(const QStringList &subtypes)
{
    d->subtypes = subtypes;
}

QStringList QWAppliance::subtypes() const
{
    return d->subtypes;
}

void QWAppliance::addSubtype(const QString &subtype)
{
    d->subtypes.push_back(subtype);
}

void QWAppliance::setAttributes(const QHash<QString, QVariant> &attributes)
{
    d->attributes = attributes;
}

QHash<QString, QVariant> QWAppliance::attributes() const
{
    return d->attributes;
}

void QWAppliance::setAttribute(const QString &name, const QVariant &value)
{
    d->attributes[name] = value;
}

QVariant QWAppliance::getAttribute(const QString &name) const
{
    return d->attributes.value(name);
}
