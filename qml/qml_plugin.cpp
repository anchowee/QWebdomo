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

#include "qml_plugin.h"
#include "qwcontroller.h"
#include "qqwdeviceconfiguration.h"
#include "qqwappliance.h"
#include "qwappproperty.h"

#include <qqml.h>

void QmlPlugin::registerTypes(const char *uri)
{
    // @uri Webdomo.Components
    qmlRegisterType<QWController>(uri, QW_VERSION_MAJOR, QW_VERSION_MINOR, "Controller");
    qmlRegisterType<QQWDeviceConfiguration>(uri, QW_VERSION_MAJOR, QW_VERSION_MINOR, "DeviceConfiguration");
    qmlRegisterType<QQWAppliance>(uri, QW_VERSION_MAJOR, QW_VERSION_MINOR, "Appliance");
    qmlRegisterType<QWAppProperty>(uri, QW_VERSION_MAJOR, QW_VERSION_MINOR, "ApplianceProperty");
}


