#include "qwcontroller.h"

QWController::QWController(QObject *parent)
{
    _configuration = new QQWDeviceConfiguration;
    _device = new QWDevice(_configuration->getConfiguration(), this);
}

QWController::~QWController()
{
    delete _configuration;
}


QWDeviceConfiguration *QWController::configuration() const
{
    return _configuration;
}

void QWController::setConfiguration(QWDeviceConfiguration *conf)
{
    _configuration = conf;
    _device = new QWDevice(_configuration->getConfiguration(), this);
    emit configurationChanged();
}
