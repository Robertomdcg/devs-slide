/*
 * commons.h
 *
 *  Created on: 13/03/2017
 *      Author: roberto
 */

#ifndef SRC_XDEVS_ROOM_COMMONS_H_
#define SRC_XDEVS_ROOM_COMMONS_H_

#include <string>
#include <iostream>

#define DEBUG_OPTION 2

using namespace std;

	typedef struct {
		bool begin;
		double time;
		int id;
		string numCores;
		string cpuPower;
		string memPower;
		string ircName;
		string serverName;
		string numThreads;
	} JobEntry;

	void jobToString(JobEntry je);




#endif /* SRC_XDEVS_ROOM_COMMONS_H_ */
