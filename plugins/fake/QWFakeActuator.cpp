#include "QWFakeActuator.h"
#ifdef QT_DEBUG
#include <QDebug>
#endif

QWFakeActuator::QWFakeActuator(QObject *parent) :
    QWActuator(parent)
{
}

void QWFakeActuator::changeState(QList<QSharedPointer<QWAppliance> > *selectedAppliances, const QHash<QString, QVariant> &newStates)
{
    const QStringList keys = newStates.keys();
    QStringList::const_iterator ki;
    QList<QSharedPointer<QWAppliance> >::iterator li;
    for(li = selectedAppliances->begin(); li != selectedAppliances->end(); li++){
        for(ki = keys.constBegin(); ki != keys.constEnd(); ki++){
            (*li)->setAttribute(*ki, newStates.value(*ki));
        }
    }
}
