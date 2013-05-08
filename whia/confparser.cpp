#include "confparser.h"

#include "utils/QWPluginsManager.h"

#include <QDir>
#include <QFile>
#include <QSettings>

QWDeviceConfiguration ConfParser::getDeviceConfiguration()
{
    QWDeviceConfiguration configuration;
    QSettings confFile(QString(CONF_PATH)+"/config", QSettings::IniFormat);
    if(confFile.status() != QSettings::NoError)
        return configuration;
    QStringList keys = confFile.allKeys();
    configuration.setUser(confFile.value("user", QVariant("guest")).toString());
    configuration.setPassword(confFile.value("password", QVariant("guest")).toString());
    configuration.setDomain(confFile.value("domain", QVariant("local")).toString());
    if(confFile.value("TLS").toBool()){
        configuration.setStreamSecurityMode(QWDeviceConfiguration::TLSEnabled);
    } else {
        configuration.setStreamSecurityMode(QWDeviceConfiguration::TLSDisabled);
    }
    configuration.setApplianceSetRoomName(confFile.value("roomName", QVariant("appliances")).toString());
    configuration.setApplianceSetServiceName(confFile.value("serviceName", QVariant("appset")).toString());
    return configuration;
}

QList<QWActuator*> ConfParser::getActuators()
{
    QList<QWActuator*> result;
    QFile confFile(QString(CONF_PATH)+"/actuators.xml");
    if(!confFile.open(QIODevice::ReadOnly | QIODevice::Text)) return result;

    QXmlStreamReader xml(&confFile);
    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if(token == QXmlStreamReader::StartElement){
            if(xml.name() == "actuators"){
                continue;
            }

            if(xml.name() == "actuator"){
                result.append(parseActuator(xml));
            }
        }
    }
    return result;
}

QWActuator *ConfParser::parseActuator(QXmlStreamReader &xml)
{
    QWActuator *actuator = 0;
    if(xml.tokenType() != QXmlStreamReader::StartElement && xml.name() == "actuator") {
        return actuator;
    }

    QXmlStreamAttributes attributes = xml.attributes();
    actuator = QWPluginsManager::loadActuator(attributes.value("type").toString(),
                                   attributes.value("version").toString().toDouble(),
                                   attributes.value("variant").toString());

    return actuator;
}
