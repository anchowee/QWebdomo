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
