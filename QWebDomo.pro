TEMPLATE = subdirs

SUBDIRS += core test

!isEmpty(QWD_DEVICE){
    DEFINES += QWD_DEVICE
    SUBDIRS += plugins whia
    QWEBDOMO_INCLUDEPATH += $$PWD/core/device
}

!isEmpty(QW_QML){
    DEFINES += QWD_QML
    SUBDIRS += qml
}

!isEmpty(QW_DEVICE){
    SUBDIRS += whia plugins
}

QWEBDOMO_INCLUDEPATH += $$PWD/core $$PWD/core/server
