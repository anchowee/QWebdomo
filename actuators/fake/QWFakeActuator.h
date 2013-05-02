#ifndef QWFAKEACTUATOR_H
#define QWFAKEACTUATOR_H

#include "QWActuator.h"

class QWFakeActuator : public QWActuator
{
    Q_OBJECT
public:
    explicit QWFakeActuator(QObject *parent = 0);
    
    QList<QWAppliance> put(QStringList &subtypes, QHash<QString, QVariant> &attributes);
    QList<QWAppliance> get(QStringList &subtypes, QHash<QString, QVariant> &attributes);
    
};

#endif // QWFAKEACTUATOR_H
