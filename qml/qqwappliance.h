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

#ifndef QQWAPPLIANCE_H
#define QQWAPPLIANCE_H

#include "../src/QWAppliance.h"
#include "qwappproperty.h"

#include <QObject>
#include <QQmlListProperty>

class QQWAppliance : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QStringList subtypes READ subtypes)
    Q_PROPERTY(QQmlListProperty<QWAppProperty> properties READ properties)
public:
    explicit QQWAppliance(QObject *parent = 0);

    void setSubtypes(const QStringList &subtypes);

    //properties
    QQmlListProperty<QWAppProperty> properties();

    //name
    QString name() const;

    //subtypes
    QStringList subtypes() const;

private:
    QString _name;
    QStringList _subtypes;
    QList<QWAppProperty*> _properties;
};

#endif // QQWAPPLIANCE_H
