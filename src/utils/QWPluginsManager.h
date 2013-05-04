#ifndef QWPLUGINSMANAGER_H
#define QWPLUGINSMANAGER_H

#include "../qwebdomo_global.h"
#include "../QWActuator.h"

#include <QObject>
#include <QString>

class QWPluginsManagerPrivate;

class QWEBDOMOSHARED_EXPORT QWPluginsManager
{
public:
    QWPluginsManager();
    ~QWPluginsManager();

    QObject* loadActuator(const QString &protocolName, int minVersion = 0.0, const QString &protocolVariant = "");

private:
    QWPluginsManagerPrivate *d;
};

#endif // QWPLUGINSMANAGER_H
