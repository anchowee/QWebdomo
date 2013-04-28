/*
 * Copyright 2013 Riccardo Ferrazzo <f.riccardo87@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

    virtual QList<QWAppliance*> put(QStringList &subtypes, QHash<QString, QVariant> &attributes) = 0;
    virtual QList<QWAppliance*> get(QStringList &subtypes, QHash<QString, QVariant> &attributes) = 0;

    QString doGet(QStringList &subtypes, QHash<QString, QVariant> &attributes);
    QString doPut(QStringList &subtypes, QHash<QString, QVariant> &attributes);

signals:
    void appliancesChanged();
    
private:
    QString formatResponse(const QString &respType, const QList<QWAppliance*> &appliances) const;

private:
    QList<QWAppliance> *_appliances;

};

#endif // QWACTUATOR_H
