#ifndef CONFPARSER_H
#define CONFPARSER_H

#include "QWActuator.h"
#include "QWDeviceConfiguration.h"

#include <QXmlStreamReader>

class ConfParser
{
public:
    static QWDeviceConfiguration getDeviceConfiguration();
    static QList<QWActuator *> getActuators();

private:
    static QWActuator *parseActuator(QXmlStreamReader &xml);
};

#endif // CONFPARSER_H
