#include "QWPluginsManager.h"

#include <QPluginLoader>
#include <QJsonObject>
#include <QDir>

QWActuator* QWPluginsManager::loadActuator(const QString &protocolName, int minVersion, const QString &protocolVariant)
{
    QDir pluginsDir(PLUGINS_PATH);
    foreach(QString filename, pluginsDir.entryList(QDir::Files)){
        QPluginLoader *loader = new QPluginLoader(pluginsDir.absoluteFilePath(filename));
        QJsonObject metadata = loader->metaData().value("MetaData").toObject();
        QJsonObject protocol = metadata.value("protocol").toObject();
        int pluginVersion = metadata.value("version").toString().toInt();
        if(!protocol.isEmpty()){
            if(protocol.value("name").toString() == protocolName
                    && pluginVersion > minVersion
                    && protocol.value("variant").toString() == protocolVariant){
                return qobject_cast<QWActuator*>(loader->instance());
            }
        }
    }
    return 0;
 }
