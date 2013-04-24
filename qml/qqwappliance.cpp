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

#include "qqwappliance.h"

QQWAppliance::QQWAppliance(QObject *parent) :
    QObject(parent)
{
}


QQmlListProperty<QWAppProperty> QQWAppliance::properties()
{
    return QQmlListProperty<QWAppProperty>(this, _properties);
}

void QQWAppliance::setProperties(const QHash<QString, QVariant> &properties)
{
    for(int i = 0; i< _properties.length(); i++){
        if(properties.contains(_properties.at(i)->name())){
            properties[_properties.at(i)->name()] = _properties.at(i)->value();
        }
    }
    emit propertiesChanged();
}

QString QQWAppliance::name() const
{
    return _name;
}

void QQWAppliance::setName(const QString &name)
{
    _name = name;
}

QStringList QQWAppliance::subtypes() const
{
    return _subtypes;
}

void QQWAppliance::setSubtypes(const QStringList &subtypes)
{
    _subtypes = subtypes;
}

bool QQWAppliance::match(const QStringList &subtypes)
{
    for(int i = 0; i < subtypes.length(); i++){
        bool match = false;
        for(int j = 0; j < _subtypes.length(); j++){
            if(subtypes[i] == _subtypes[j])
                match = true;
        }
        if(!match) return false;
    }
}
