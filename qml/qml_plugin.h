#ifndef QML_PLUGIN_H
#define QML_PLUGIN_H

#include <QQmlExtensionPlugin>

class QmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri);
};

#endif // QML_PLUGIN_H

