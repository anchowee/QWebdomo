#ifndef QWFAKEACTUATOR_H
#define QWFAKEACTUATOR_H

#include "QWActuator.h"

class QWFakeActuator : public QWActuator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Webdomo.Plugin.QWActuator/1.0" FILE "fakeActuator.json")
    Q_INTERFACES(QWActuator)
public:
    explicit QWFakeActuator(QObject *parent = 0);
    
    void changeState(QList<QSharedPointer<QWAppliance> > *selectedAppliances, const QHash<QString, QVariant> &newStates);
    
};

#endif // QWFAKEACTUATOR_H
