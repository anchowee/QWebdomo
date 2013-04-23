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

#ifndef QWACTIONPARSER_H
#define QWACTIONPARSER_H

#include "qwebdomo_global.h"
#include "QWParser.h"

class QWEBDOMOSHARED_EXPORT QWActionParser : public QWParser
{
    Q_OBJECT
public:
    explicit QWActionParser(QObject *parent = 0);

public slots:
    void parse(const QString &bareJid, MessageType type, const QJsonValue &content);
};

#endif // QWACTIONPARSER_H
