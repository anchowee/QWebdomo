#include "QWFakeActuator.h"

QWFakeActuator::QWFakeActuator(QObject *parent) :
    QWActuator(parent)
{
}

QList<QWAppliance> QWFakeActuator::put(QStringList &subtypes, QHash<QString, QVariant> &attributes)
{
    return find(subtypes);
}

QList<QWAppliance> QWFakeActuator::get(QStringList &subtypes, QHash<QString, QVariant> &attributes)
{
    return find(subtypes);
}
