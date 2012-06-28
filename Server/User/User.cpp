/*
 * User.cpp
 *
 *  Created on: Jun 27, 2012
 *      Author: jmonk
 */

#include "User.h"
#include "CPacket.h"
#include "CCommunicator.h"
#include "Server.h"

namespace dvs {

User::User(CCommunicator* comm) {
	this->comm = comm;
	this->comm->user = this;
	this->id = Server::allocateUID();
	Server::setUser(this->id, this);
}

User::~User() {
	Server::freeUID(id);
}

void User::send(CPacket* packet) {
	comm->send(packet);
}

unsigned int User::getId() {
	return id;
}

}