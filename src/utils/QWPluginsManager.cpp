#include "QWPluginsManager.h"

#include <QPluginLoader>
#include <QJsonObject>
#include <QDir>

class QWPluginsManagerPrivate {
public:
    QWPluginsManagerPrivate(){
        pluginsDir = QDir(PLUGINS_PATH);
    }

    QDir pluginsDir;
    QList<QPluginLoader*> plugins;
};


QWPluginDescriptor::QWPluginDescriptor(const QString &name, QObject *instance)
    :className(name), instance(instance) {}

bool QWPluginDescriptor::isNull() const
{
    if(className == "" && instance == 0) return true;
    return false;
}

QWPluginsManager::QWPluginsManager() :
    d(new QWPluginsManagerPrivate)
{
}

QWPluginsManager::~QWPluginsManager()
{
    delete d;
}

QWPluginDescriptor QWPluginsManager::loadActuator(const QString &protocolName, int minVersion, const QString &protocolVariant)
{
    foreach(QString filename, d->pluginsDir.entryList(QDir::Files)){
        QPluginLoader *loader = new QPluginLoader(d->pluginsDir.absoluteFilePath(filename));
        QJsonObject metadata = loader->metaData().value("MetaData").toObject();
        QJsonObject protocol = metadata.value("protocol").toObject();
        int pluginVersion = metadata.value("version").toString().toInt();
        if(!protocol.isEmpty()){
            if(protocol.value("name").toString() == protocolName
                    && pluginVersion > minVersion
                    && protocol.value("variant").toString() == protocolVariant){
                 return QWPluginDescriptor(loader->metaData().value("className").toString(), loader->instance());
            }
        }
    }
    return QWPluginDescriptor();
 }

