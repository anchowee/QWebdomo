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

#ifndef QWAPPLIANCE_H
#define QWAPPLIANCE_H

#include"qwebdomo_global.h"

#include <QHash>
#include <QStringList>
#include <QSharedDataPointer>
#include <QVariant>

class QWAppliancePrivate;

class QWEBDOMOSHARED_EXPORT QWAppliance
{
public:
    QWAppliance();
    QWAppliance(const QWAppliance &other);
    ~QWAppliance();

    void setName(const QString &name);
    QString name() const;

    //subtypes are sorted
    void setSubtypes(const QStringList &subtypes);
    QStringList subtypes() const;
    void addSubtype(const QString &subtype);

    void setAttributes(const QHash<QString, QVariant> &attributes);
    QHash<QString, QVariant> attributes() const;
    void setAttribute(const QString &name, const QVariant &value);
    QVariant getAttribute(const QString &name) const;

    QWAppliance &operator=(const QWAppliance &rhs);
    bool operator==(const QWAppliance &other);

private:
    QSharedDataPointer<QWAppliancePrivate> d;
};

#endif // QWAPPLIANCE_H
