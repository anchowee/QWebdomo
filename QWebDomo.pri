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

#Plugins directory
PLUGINS_PATH = $$PREFIX/share/webdomo/plugins
DEFINES += "PLUGINS_PATH=\\\"$${PLUGINS_PATH}\\\""
