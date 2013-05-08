QT       -= gui

isEmpty(PREFIX) {
    unix {
        PREFIX = /usr
    } else {
        PREFIX = $$[QT_INSTALL_PREFIX]
    }
}

isEmpty(LIBDIR) {
    LIBDIR = lib
}

#Version numbers
QW_VERSION_MAJOR=0
DEFINES += "QW_VERSION_MAJOR=$${QW_VERSION_MAJOR}"
QW_VERSION_MINOR=1
DEFINES += "QW_VERSION_MINOR=$${QW_VERSION_MINOR}"
QW_VERSION = $${QW_VERSION_MAJOR}.$${QW_VERSION_MINOR}
DEFINES += "QW_VERSION=\\\"$${QW_VERSION}\\\""

#Plugins directory
PLUGINS_PATH = $$PREFIX/share/webdomo/plugins
DEFINES += "PLUGINS_PATH=\\\"$${PLUGINS_PATH}\\\""

#conf directory
isEmpty(CONF_PATH) {
    CONF_PATH = /etc/whia
}
DEFINES += "CONF_PATH=\\\"$${CONF_PATH}\\\""
