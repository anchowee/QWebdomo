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

#include "QWAppliance.h"

class QWAppliancePrivate : public QSharedData {
public:
    QWAppliancePrivate(){}

    QWAppliancePrivate(const QWAppliancePrivate &other) :
        QSharedData(other),
        name(other.name),
        subtypes(other.subtypes),
        attributes(other.attributes) {}

    QString name;

    //ordered list of string
    QStringList subtypes;

    QHash<QString, QVariant> attributes;
};

QWAppliance::QWAppliance() :
    d(new QWAppliancePrivate)
{
}

QWAppliance::QWAppliance(const QWAppliance &other) :
    d(other.d)
{
}

QWAppliance::~QWAppliance()
{
}


void QWAppliance::setName(const QString &name)
{
    d->name = name;
}

QString QWAppliance::name() const
{
    return d->name;
}

void QWAppliance::setSubtypes(const QStringList &subtypes)
{
    d->subtypes = subtypes;
    d->subtypes.sort();
}

QStringList QWAppliance::subtypes() const
{
    return d->subtypes;
}

void QWAppliance::addSubtype(const QString &subtype)
{
    int pos = QWAppliance::binFindPosition(0, d->subtypes.length()-1, d->subtypes, subtype);
    d->subtypes.insert(pos, subtype);
}

void QWAppliance::setAttributes(const QHash<QString, QVariant> &attributes)
{
    d->attributes = attributes;
}

QHash<QString, QVariant> QWAppliance::attributes() const
{
    return d->attributes;
}

void QWAppliance::setAttribute(const QString &name, const QVariant &value)
{
    d->attributes[name] = value;
}

QVariant QWAppliance::getAttribute(const QString &name) const
{
    return d->attributes.value(name);
}

int QWAppliance::binFindPosition(int x, int z, const QStringList &array, const QString &string)
{
    if(x<z){
        int y = x+z/2;
        if(array.at(y) < string){
            return QWAppliance::binFindPosition(x, y-1, array, string);
        } else {
            return QWAppliance::binFindPosition(y+1, z, array, string);
        }
    }
    while(x < array.length()-1 && array.at(x) < string)
        x++;
    return x;
}

QWAppliance &QWAppliance::operator =(const QWAppliance &rhs)
{
    if(this == &rhs) return *this;
    d = rhs.d;
    return *this;
}

bool QWAppliance::operator ==(const QWAppliance &other)
{
    if(other.subtypes() == subtypes() && other.name() == name()) return true;
    return false;
}
