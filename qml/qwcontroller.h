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

#ifndef QWCONTROLLER_H
#define QWCONTROLLER_H

#include "qwcommanderdevice.h"
#include "qqwdeviceconfiguration.h"
#include "qqwappliance.h"

#include <QObject>
#include <QQmlListProperty>

//TODO: write a function to make a get request and a put one
class QWController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QWController)
    Q_PROPERTY(QQmlListProperty<QQWAppliance> appliances READ appliances NOTIFY appliancesChanged)
    Q_PROPERTY(QQWDeviceConfiguration *configuration READ configuration WRITE setConfiguration NOTIFY configurationChanged)
public:
    QWController(QObject *parent = 0);
    ~QWController();

    //appliances
    QQmlListProperty<QQWAppliance> appliances();

    //Configuration
    QQWDeviceConfiguration *configuration() const;
    void setConfiguration(QQWDeviceConfiguration *conf);

signals:
    void appliancesChanged();
    void configurationChanged();
    void connected();

public slots:
    changeApplianceProperty(const QQWAppliance *app, const QString &name, const QVariant &newValue)

private slots:
    void updateAppliances(const QList<QQWAppliance *> &appList);
    void addAppliances(const QList<QQWAppliance *> &appList);

private:
    QWCommanderDevice *_device;
    QQWDeviceConfiguration *_configuration;
    QList<QQWAppliance*> _appliances;
};

#endif // QWCONTROLLER_H

