/*
 * Copyright 2013 Riccardo Ferrazzo <f.riccardo87@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "confparser.h"

#include "utils/QWPluginsManager.h"

#include <QDir>
#include <QFile>
#include <QSettings>

bool Configurator::setDeviceConfiguration(const QWDeviceConfiguration &config)
{
    QSettings confFile(QString(CONF_PATH)+"/config", QSettings::IniFormat);
    if(confFile.status() != QSettings::NoError){
        return false;
    }
    confFile.setValue("user", config.user());
    confFile.setValue("password", config.password());
    confFile.setValue("domain", config.domain());
    confFile.setValue("TLS", config.streamSecurityMode() == QWDeviceConfiguration::TLSEnabled);
    confFile.setValue("roomName", config.applianceSetRoomName());
    confFile.setValue("serviceName", config.applianceSetServiceName());
    return true;
}

QWDeviceConfiguration Configurator::getDeviceConfiguration()
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

QList<QWActuator*> Configurator::getActuators()
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

QWActuator *Configurator::parseActuator(QXmlStreamReader &xml)
{
    QWActuator *actuator = 0;
    QStringList subtypes;

    if(xml.tokenType() != QXmlStreamReader::StartElement && xml.name() == "actuator") {
        return actuator;
    }

    QXmlStreamAttributes attributes = xml.attributes();
    actuator = QWPluginsManager::loadActuator(attributes.value("type").toString(),
                                   attributes.value("version").toString().toDouble(),
                                   attributes.value("variant").toString());

    xml.readNext();

    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "actuator")){

        if(xml.name() == "subtype" && xml.tokenType() == QXmlStreamReader::StartElement){
            subtypes.append(xml.attributes().value("name").toString());
        }

        if(xml.name() == "appliance" && xml.tokenType() == QXmlStreamReader::StartElement){
            QWAppliance app;
            app.setName(xml.attributes().value("name").toString());
            app.setSubtypes(subtypes);

            xml.readNext();
            while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "appliance")){
                if(xml.name() == "var"){
                    const QString name(xml.attributes().value("name").toString());
                    //TODO: value type should be different from string
                    const QVariant value(xml.attributes().value("value").toString());
                    app.setAttribute(name, value);
                }

                xml.readNext();
            }
            actuator->addAppliance(app);
        }

        xml.readNext();
    }

    return actuator;
}
