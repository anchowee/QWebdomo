#ifndef QWPLUGINSMANAGER_H
#define QWPLUGINSMANAGER_H

#include "../qwebdomo_global.h"
#include "../QWActuator.h"

#include <QObject>
#include <QString>

class QWEBDOMOSHARED_EXPORT QWPluginsManager
{
public:
    static QWActuator *loadActuator(const QString &protocolName, int minVersion = 0.0, const QString &protocolVariant = "");
};

#endif // QWPLUGINSMANAGER_H
