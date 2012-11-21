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
 * FloatField.h
 *
 *  Created on: Jun 18, 2012
 *      Author: jmonk
 */

#ifndef FLOATFIELD_H_
#define FLOATFIELD_H_

#include "Field.h"

namespace dvs {

class FloatField: public dvs::Field {
public:
	FloatField(string name, unsigned char id, bool writable, bool vol, Device* device);
	virtual ~FloatField();

	void setRealString(string val);

	void setString(unsigned char* value);

	unsigned char* getString();

	unsigned int getLength();

	void increment();

	float getFloat();
private:
	float value;
	unsigned char l[5];
};

} /* namespace dvs */
#endif /* FLOATFIELD_H_ */
