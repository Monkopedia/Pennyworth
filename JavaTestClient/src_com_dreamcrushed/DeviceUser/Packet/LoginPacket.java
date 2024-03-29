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
package com.dreamcrushed.DeviceUser.Packet;

import com.dreamcrushed.DeviceUser.NetworkManager;
import com.dreamcrushed.DeviceUser.Util;


public class LoginPacket extends Packet{
	private String user;
	private String pass;

	public LoginPacket(String user, String pass) {
		super(new String[0]);
		this.user = user;
		this.pass = pass;
	}

	@Override
	public String packetString() {
		return Util.concat(new String[] {PacketType.LOGIN.getType() + "", NetworkManager.getUserId() + "", user, pass}, ":");
	}

}
