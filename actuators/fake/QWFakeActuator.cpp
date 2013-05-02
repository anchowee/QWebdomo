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
    QList<QWAppliance> apps = find(subtypes);
    for(int i = 0; i != apps.length(); i++){
        QHash<QString, QVariant>::const_iterator hi;
        for(hi = attributes.constBegin(); hi != attributes.constEnd(); ++hi){
            apps[i].setAttribute(hi.key(), hi.value());
        }
    }
    return apps;
}
