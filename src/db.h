/**
 * db.c : wrapper class around pmdb_t
 *
 *  Copyright (c) 2011 Rémy Oudompheng <remy@archlinux.org>
 *
 *  This file is part of pyalpm.
 *
 *  pyalpm is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  pyalpm is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with pyalpm.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _PYALPM_DB_H
#define _PYALPM_DB_H

#include <Python.h>

typedef struct _AlpmDB {
  PyObject_HEAD
  pmdb_t *c_data;
} AlpmDB;

PyTypeObject AlpmDBType;

PyObject *pyalpm_db_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

void init_pyalpm_db(PyObject *module);

#endif // _PYALPM_DB_H
