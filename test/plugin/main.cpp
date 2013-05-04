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

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QPluginLoader>
#include <QJsonObject>

int main(int argc, char *argv[])
{
    QDir pluginsDir(PLUGINS_PATH);
    foreach(QString filename, pluginsDir.entryList(QDir::Files)){
        QPluginLoader loader(pluginsDir.absoluteFilePath(filename));
        QJsonObject metadata = loader.metaData();
        QJsonObject protocol = metadata.value("protocol").toObject();
        if(protocol){
            if(protocol.value("name").toString() == "fake")
                qDebug() << "protocol fake, version: " << protocol.value("version").toString();
        }
    }
}
