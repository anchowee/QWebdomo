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
#include "utils/QWPluginsManager.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QWActuator *actuator = QWPluginsManager::loadActuator("fake");
    if(actuator == 0){
        qDebug() << "actuator not found";
        return 1;
    }
    QWAppliance app;
    app.setName("prova");
    app.addSubtype("home");
    app.addSubtype("example");
    app.addSubtype("aaa");
    app.addSubtype("aab");
    app.addSubtype("zero");
    app.addSubtype("cracker");
    app.setAttribute("value", QVariant(0));
    for(int i = 0; i < app.subtypes().length(); i++){
        qDebug() << app.subtypes().at(i);
    }
    actuator->addAppliance(app);
    QStringList sl;
    QHash<QString, QVariant> qh;
    qDebug() << "-- doGet empty test";
    qDebug() << actuator->get(sl,qh);
    sl.append("home");
    sl.append("aab");
    qDebug() << "-- doGet with home subtype";
    qDebug() << actuator->get(sl, qh);
    qDebug() << "done";
}
