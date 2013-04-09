#include "QWActuator.h"

QWActuator::QWActuator(QObject *parent) :
    QObject(parent)
{}

QStringList QWActuator::getSubtypes() const
{
    QStringList subtypes;
    for(int i = 0; i < _appliances->length(); i++){
        subtypes.append(_appliances->at(i).subtypes());
    }
    return subtypes;
}
