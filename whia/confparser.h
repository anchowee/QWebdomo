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

#ifndef CONFPARSER_H
#define CONFPARSER_H

#include "QWActuator.h"
#include "QWDeviceConfiguration.h"

#include <QXmlStreamReader>

class Configurator
{
public:
    static bool setDeviceConfiguration(const QWDeviceConfiguration &config);

    static QWDeviceConfiguration getDeviceConfiguration();
    static QList<QWActuator *> getActuators();

private:
    static QPair<QString, QVariant> getVariable(QXmlStreamReader &xml);
    static QWActuator *parseActuator(QXmlStreamReader &xml);
};

#endif // CONFPARSER_H
