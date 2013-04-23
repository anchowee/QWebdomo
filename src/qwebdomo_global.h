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

#ifndef QWEBDOMO_GLOBAL_H
#define QWEBDOMO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QWEBDOMO_LIBRARY)
#  define QWEBDOMOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QWEBDOMOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QWEBDOMO_GLOBAL_H
