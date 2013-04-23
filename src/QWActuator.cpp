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
