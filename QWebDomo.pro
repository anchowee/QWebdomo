TEMPLATE = subdirs

SUBDIRS += core

!isEmpty(QW_DEVICE){
    DEFINES += QW_DEVICE
    SUBDIRS += plugins whia
}

!isEmpty(QW_QML){
    DEFINES += QW_QML
    SUBDIRS += qml
}

!isEmpty(QW_TEST){
    SUBDIRS += test
}
