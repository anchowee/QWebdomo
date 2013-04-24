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

    virtual QString put(const QStringList &subtypes, const QHash<QString, QVariant> &attributes) const = 0;
    virtual QString get(const QStringList &subtypes, const QHash<QString, QVariant> &attributes) const = 0;

signals:
    void appliancesChanged();
    
private:
    QString formatResponse(const QStringList &subtypes, const QHash<QString, QVariant> &attributes) const;

private:
    QList<QWAppliance> *_appliances;

};

#endif // QWACTUATOR_H
