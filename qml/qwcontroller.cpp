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

#include "qwcontroller.h"
#include <QMultiHash>
#ifdef QT_DEBUG
#include <QDebug>
#endif

class QWControllerPrivate {
public:
    QWControllerPrivate() : configuration(0), device(0) {}

    QWCommanderDevice *device;
    QQWDeviceConfiguration *configuration;
    QMultiHash<QString, QQWAppliance*> appliances;
};

QWController::QWController(QObject *parent) : QObject(parent), d(new QWControllerPrivate)
{
}

QWController::~QWController()
{
    delete d;
}


QQWDeviceConfiguration *QWController::configuration() const
{
    return d->configuration;
}

void QWController::setConfiguration(QQWDeviceConfiguration *conf)
{
    d->configuration = conf;
    d->device = new QWCommanderDevice(d->configuration->getConfiguration(), this);

    connect(d->device, SIGNAL(updateAppliances(QString, QList<QQWAppliance*>)),
            this, SLOT(updateAppliances(QString, QList<QQWAppliance*>)));

    connect(d->device, SIGNAL(setAppliances(QString, QList<QQWAppliance*>)),
            this, SLOT(updateAppliances(QString,QList<QQWAppliance*>)));

    connect(d->device, SIGNAL(connected()), this, SIGNAL(connected()));

    connect(d->device, SIGNAL(presenceReceived(QXmppPresence)),
            this, SLOT(connectedDeviceChanged(QXmppPresence)));

    emit configurationChanged();
}

QQmlListProperty<QQWAppliance> QWController::appliances()
{
    QList<QQWAppliance*> apps = d->appliances.values();
    return QQmlListProperty<QQWAppliance>(this, apps);
}


void QWController::updateAppliances(const QString &deviceJid, const QList<QQWAppliance *> &appList)
{
    QList<QQWAppliance *>::const_iterator updatesIt;
    QHash<QString, QQWAppliance*>::iterator i = d->appliances.find(deviceJid);
    if(i == d->appliances.end()){
        for(updatesIt = appList.constBegin(); updatesIt != appList.constEnd(); updatesIt++){
            d->appliances.insert(deviceJid, *updatesIt);
        }
    } else {
        while(i != d->appliances.end()){
            for(updatesIt = appList.constBegin(); updatesIt != appList.constEnd(); updatesIt++){
                const QQWAppliance *newApp = *updatesIt;
                if(*newApp == *(i.value())){
                    i.value()->updateProperties(newApp->propertiesList());
                }
            }
            i++;
        }
    }
    emit appliancesChanged();
}

void QWController::changeApplianceProperty(const QStringList &apps, const QString &propertyName, const QVariant &newValue)
{
    QHash<QString, QVariant> properties;
    properties.insert(propertyName, newValue);
    d->device->changeAppliancesProperties(apps, properties);
}

void QWController::connectedDeviceChanged(const QXmppPresence &presence)
{
#ifdef QT_DEBUG
    qDebug() << "presence message arrived";
#endif
    if(presence.type() == QXmppPresence::Unavailable){
#ifdef QT_DEBUG
        qDebug() << presence.from() <<" has disconnected, removing appliances";
#endif
        d->appliances.remove(presence.from());
    }
    emit appliancesChanged();
}

