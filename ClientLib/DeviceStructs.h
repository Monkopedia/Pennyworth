/**
 * Pennyworth - A new smarthome protocol.
 * Copyright (C) 2012  Dream-Crusher Labs LLC
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
/*
 * DeviceStructs.h
 *
 *  Created on: Jun 21, 2012
 *      Author: jmonk
 */

#ifndef DEVICESTRUCTS_H_
#define DEVICESTRUCTS_H_

#define true 1
#define false 0

typedef enum {
	BOOL=0,
	INT,
	FLOAT,
	FIXED,
	STRING
} FieldType;

typedef struct {
	FieldType type;
	unsigned char id;
	char *name;
	unsigned char vol;
	unsigned char writable;
	unsigned char changed;
	unsigned char subscribed;
	FieldList listener;
	void* field;
} FieldDef;

#ifndef BUFFER_LENGTH
#define BUFFER_LENGTH 64
#endif

typedef struct {
	char buffer[BUFFER_LENGTH];
	char startWatch[4];
	unsigned int index;
	unsigned int length;
	unsigned int state;
	unsigned char initialized;
	unsigned char shouldBreak;
	SendRoutine send;
} CommManager;

typedef struct {
	CommManager comm;
	unsigned int deviceId;
	unsigned char roomId;
	char *name;
	char *cname;
	unsigned int x;
	unsigned int y;
	unsigned char icon;
	unsigned int nfields;
	FieldDef *fields;
} Device;

typedef struct {
	unsigned char value;
} BoolField;

typedef struct {
	unsigned int value;
} IntField;

typedef struct {
	unsigned int value;
	unsigned int one;
} FixedField;

typedef struct {
	char* value;
} StringField;

#endif /* DEVICESTRUCTS_H_ */
