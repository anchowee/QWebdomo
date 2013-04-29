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

QList<QWAppProperty *> QQWAppliance::propertiesList() const
{
    return _properties;
}

void QQWAppliance::addProperty(const QString &name, const QVariant &value)
{
    QWAppProperty *prop = new QWAppProperty();
    prop->setName(name);
    prop->setValue(value);
    _properties.append(prop);
    emit propertiesChanged();
}

void QQWAppliance::updateProperties(const QList<QWAppProperty *> &properties)
{
    QList<QWAppProperty *>::const_iterator it;
    QList<QWAppProperty *>::iterator it2;
    for(it = properties.constBegin(); it != properties.constEnd(); ++it){
        const QWAppProperty *prop = *it;
        for(it2 = _properties.begin(); it2 != _properties.end(); ++it2){
            QWAppProperty *myProp = *it2;
            if(prop->name() == myProp->name()){
                myProp->setValue(prop->value());
                continue;
            }
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

void QQWAppliance::addSubtype(const QString &subtype)
{
    _subtypes.append(subtype);
}

bool QQWAppliance::operator==(const QQWAppliance &other) const
{
    if(other.name() != this->name()) return false;

    QStringList::const_iterator otherIt;
    for(otherIt = other.subtypes().constBegin(); otherIt != other.subtypes().constEnd(); ++otherIt){
        const QString str = *otherIt;
        if(!_subtypes.contains(str)) return false;
    }
    return true;
}
