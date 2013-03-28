#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <QObject>

#include "types.h"

class Actuator : public QObject
{
    Q_OBJECT
public:
    explicit Actuator(QObject *parent = 0);

    void getProperty();
    void setProperty();
    Types getType() const { return _type; }

signals:
    
public slots:

private:
    Types _type;
    QHash<Commands, int> *_properties;

};

#endif // ACTUATOR_H
