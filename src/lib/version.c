/***************************************************************************
 *   Copyright (C) 2019 by Kyle Hayes                                      *
 *   Author Kyle Hayes  kyle.hayes@gmail.com                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "version.h"

/*
 * The library version in various ways.
 *
 * The defines are for building in specific versions and then
 * checking them against a dynamically linked library.
 */

const char *VERSION="2.1.0";

#define LIB_VER_MAJOR (2)
#define LIB_VER_MINOR (1)
#define LIB_VER_PATCH (0)

const int version_major = LIB_VER_MAJOR;
const int version_minor = LIB_VER_MINOR;
const int version_patch = LIB_VER_PATCH;
