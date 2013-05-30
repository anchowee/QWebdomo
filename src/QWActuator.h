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

#ifndef QWACTUATOR_H
#define QWACTUATOR_H

#include "QWAppliance.h"

#include <QObject>
#include <QStringList>
#include <QSharedPointer>

class QWActuatorPrivate;

class QWActuator : public QObject
{
    Q_OBJECT
public:
    explicit QWActuator(QObject *parent = 0);
    ~QWActuator();

    QStringList getSubtypes() const; //TODO: maybe this can be deleted

    void setVars(const QHash<QString, QVariant> &vars);
    QVariant var(const QString &name);

    virtual void initialize();
    void start();
    bool isStarted();

    virtual void changeState(QList<QSharedPointer<QWAppliance> > *selectedAppliances, const QHash<QString, QVariant> &newStates) = 0;

    virtual void put(const QStringList &subtypes, const QHash<QString, QVariant> &attributes);
    virtual void get(const QString &senderJid, const QStringList &subtypes, const QHash<QString, QVariant> &attributes);

signals:
    void appliancesChanged();
    void notifyGet(const QString &senderJid, const QString &result);
    void notifyPut(const QString &result);

public slots:
    void addAppliance(const QSharedPointer<QWAppliance> app);

protected:
    QList<QSharedPointer<QWAppliance> > find(const QStringList &subtypes, const QHash<QString, QVariant> &attributes = QHash<QString, QVariant>());
    QString formatResponse(const QString &respType, const QList<QSharedPointer<QWAppliance> > &appliances) const;

private:
    QWActuatorPrivate *d;
};

Q_DECLARE_INTERFACE(QWActuator, "Webdomo.Plugin.QWActuator/1.0")

#endif // QWACTUATOR_H
