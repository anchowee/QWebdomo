#ifndef QWPLUGINSMANAGER_H
#define QWPLUGINSMANAGER_H

#include "../qwebdomo_global.h"

#include <QObject>
#include <QString>

class QWPluginsManagerPrivate;

class QWEBDOMOSHARED_EXPORT QWPluginDescriptor{
public:
    QWPluginDescriptor(const QString &name = "", QObject *instance = 0);

    bool isNull() const;

    const QString className;
    QObject *instance;
};

class QWEBDOMOSHARED_EXPORT QWPluginsManager
{
public:
    QWPluginsManager();
    ~QWPluginsManager();

    QWPluginDescriptor loadActuator(const QString &protocolName, int minVersion = 0.0, const QString &protocolVariant = "");

private:
    QWPluginsManagerPrivate *d;
};

#endif // QWPLUGINSMANAGER_H
