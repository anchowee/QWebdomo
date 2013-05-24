#include "QWFakeActuator.h"
#ifdef QT_DEBUG
#include <QDebug>
#endif

QWFakeActuator::QWFakeActuator(QObject *parent) :
    QWActuator(parent)
{
}

void QWFakeActuator::changeState(QList<QWAppliance> *selectedAppliances, const QHash<QString, QVariant> &newStates)
{
    const QStringList keys = newStates.keys();
    QStringList::const_iterator ki;
    QList<QWAppliance>::iterator li;
    for(li = selectedAppliances->begin(); li != selectedAppliances->end(); li++){
        for(ki = keys.constBegin(); ki != keys.constEnd(); ki++){
#ifdef QT_DEBUG
            qDebug() << "changing value " << *ki << " to " << newStates.value(*ki);
#endif
            li->setAttribute(*ki, newStates.value(*ki));
        }
    }
}
