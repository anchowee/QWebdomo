TEMPLATE = subdirs

SUBDIRS += src test actuators whia

QWEBDOMO_INCLUDEPATH = $$PWD/src $$PWD/src/server

!isEmpty(WITH_QML_PLUGINS){
    SUBDIRS += qml
}
