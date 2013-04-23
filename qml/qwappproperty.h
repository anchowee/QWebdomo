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

#ifndef QWAPPPROPERTY_H
#define QWAPPPROPERTY_H

#include <QObject>
#include <QVariant>

class QWAppProperty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit QWAppProperty(QObject *parent = 0);

    //name
    QString name() const;
    void setName(const QString &name);

    //value
    QVariant value() const;
    void setValue(const QVariant &value);

signals:
    void nameChanged();
    void valueChanged();

private:
    QString _name;
    QVariant _value;
    
};

#endif // QWAPPPROPERTY_H
