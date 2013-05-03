TEMPLATE = subdirs

SUBDIRS += \
    client \
    plugin

!isEmpty(QWD_USE_SERVER){
    SUBDIRS += server_example
}
