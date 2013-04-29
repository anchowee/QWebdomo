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

#include "qwappproperty.h"

QWAppProperty::QWAppProperty(QObject *parent) :
    QObject(parent)
{
}

QString QWAppProperty::name() const
{
    return _name;
}

void QWAppProperty::setName(const QString &name)
{
    _name = name;
}

QVariant QWAppProperty::value() const
{
    return _value;
}

void QWAppProperty::setValue(const QVariant &value)
{
    _value = value;
}

bool QWAppProperty::operator==(const QWAppProperty &other) const
{
    if(_name == other.name() && _value == other.value()) return true;
    return false;
}
