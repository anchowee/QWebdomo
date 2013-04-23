#include "qml_plugin.h"
#include "qwcontroller.h"
#include "qqwdeviceconfiguration.h"
#include "qqwappliance.h"
#include "qwappproperty.h"

#include <qqml.h>

void QmlPlugin::registerTypes(const char *uri)
{
    // @uri Webdomo.Components
    qmlRegisterType<QWController>(uri, 0, 1, "Controller");
    qmlRegisterType<QQWDeviceConfiguration>(uri, 0, 1, "DeviceConfiguration");
    qmlRegisterType<QQWAppliance>(uri, 0, 1, "Appliance");
    qmlRegisterType<QWAppProperty>(uri, 0, 1, "ApplianceProperty");
}


