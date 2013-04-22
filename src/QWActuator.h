#ifndef QWACTUATOR_H
#define QWACTUATOR_H

#include "QWAppliance.h"

#include <QObject>
#include <QStringList>

class QWActuator : public QObject
{
    Q_OBJECT
public:
    explicit QWActuator(QObject *parent = 0);

    QStringList getSubtypes() const;

    virtual void put(const QStringList &subtypes, const QHash<QString, QVariant> &attributes) const = 0;
    virtual void get(const QStringList &subtypes, const QHash<QString, QVariant> &attributes) const = 0;

signals:
    void appliancesChanged();
    
private:
    QList<QWAppliance> *_appliances;

};

#endif // QWACTUATOR_H
