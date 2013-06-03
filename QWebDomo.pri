QT       -= gui
INCLUDEPATH += $$PWD/core $$PWD/core/device $$PWD/core/server
DEFINES += QW_LIBRARY

isEmpty(PREFIX) {
    unix {
        PREFIX = /usr
    } else {
        PREFIX = $$[QT_INSTALL_PREFIX]
    }
}

#Libraries directory
isEmpty(LIBDIR) {
    LIBDIR = lib
}

#Executables directory
isEmpty(BINDIR) {
    BINDIR = bin
}

#Configurations directory
isEmpty(CONF_PATH) {
    CONF_PATH = /etc/whia
}

#Type of library (static, shared)
isEmpty(QW_LIBRARY_TYPE){
    android{
        QW_LIBRARY_TYPE=staticlib
        DEFINES += QW_STATIC
    } else {
        QW_LIBRARY_TYPE=shared
    }
}

#Version numbers
QW_VERSION_MAJOR=0
DEFINES += "QW_VERSION_MAJOR=$${QW_VERSION_MAJOR}"
QW_VERSION_MINOR=5
DEFINES += "QW_VERSION_MINOR=$${QW_VERSION_MINOR}"
QW_VERSION = $${QW_VERSION_MAJOR}.$${QW_VERSION_MINOR}
DEFINES += "QW_VERSION=\\\"$${QW_VERSION}\\\""

## CONSTANTS ##

#Plugins directory
PLUGINS_PATH = $$PREFIX/$$LIBDIR/webdomo/plugins
DEFINES += "PLUGINS_PATH=\\\"$${PLUGINS_PATH}\\\""

#Configuration directory
DEFINES += "CONF_PATH=\\\"$${CONF_PATH}\\\""
