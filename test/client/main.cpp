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

#include <QCoreApplication>

#include <qxmpp/QXmppConfiguration.h>

#include "../../src/QWControlDevice.h"
#include "../../src/QWDeviceConfiguration.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWDeviceConfiguration conf;
    conf.setDomain("picci");
    conf.setStreamSecurityMode(QWDeviceConfiguration::TLSDisabled);
    conf.setUser("appliance");
    conf.setPassword("123");

    QWControlDevice dev(conf);

    return a.exec();
}
