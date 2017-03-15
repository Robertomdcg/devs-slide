/*
 * RoomDevs.h
 *
 *  Created on: 03/12/2016
 *      Author: roberto
 */

#ifndef SRC_XDEVS_ROOMDEVS_H_
#define SRC_XDEVS_ROOMDEVS_H_

#include <xdevs/core/modeling/Port.h>
#include <xdevs/core/modeling/Atomic.h>
#include <xdevs/core/modeling/Event.h>
#include <fstream>
#include <iostream>
#include <string>
#icnlude <vector>
#include "rack-irc.h"

class RoomDevs: public Coupled {
public:
	RoomDevs();
	std::unordered_map<std::string, RackDevs> racks;
	IRCDevs irc;
	Port iJobs;
	Port oPower;
	virtual ~RoomDevs();
protected:
	const std::string &roomType;
	const std::string &IRCModel;
	std::vector<RackAndIRC::RackAndIRCParams> rackIRC;
};


#endif /* SRC_XDEVS_ROOMDEVS_H_ */
