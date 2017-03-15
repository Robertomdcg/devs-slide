/*
 * commons.cpp
 *
 *  Created on: 14/03/2017
 *      Author: roberto
 */
#include "commons.h"

void jobToString(JobEntry je){
			cout << "begin: "<< je.begin <<
					" time: "<< je.time <<
					" id: " << je.id <<
					" numcores: " << je.numCores
					<< " cpuPower: " << je.cpuPower
					<< " memPower: " << je.memPower
					<< " ircName: " << je.ircName
					<< " serverName: " << je.serverName
					<< " numThreads: " << je.numThreads
					<< endl;
	}
