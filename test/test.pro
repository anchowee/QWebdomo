TEMPLATE = subdirs

SUBDIRS += \
    client \
    plugin

!isEmpty(QW_SERVER){
    SUBDIRS += server_example
}
