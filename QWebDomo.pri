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
