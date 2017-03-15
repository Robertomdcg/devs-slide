/*
 * DevsJobsOffline.h
 *
 *  Created on: 14/07/2016
 *      Author: jlrisco
 */

#ifndef SRC_XDEVS_DEVSJOBSOFFLINE_H_
#define SRC_XDEVS_DEVSJOBSOFFLINE_H_

#include "core/modeling/Port.h"
#include "core/modeling/Atomic.h"
#include "core/modeling/Event.h"
#include "commons.h"
#include <fstream>
#include <iostream>
#include <string>

class DevsJobsOffline : public Atomic {
public:

	Port iStop;
	Port oOut;
	DevsJobsOffline(const std::string& name, const std::string& jobsFilePath);
	virtual ~DevsJobsOffline();

	// DEVS protocol
	virtual void initialize();
	virtual void exit();
	virtual void deltint();
	virtual void deltext(double e);
	virtual void lambda();

	// PARTICULAR FUNCTIONS
	JobEntry* getNextEntry();
protected:
	double initialTime;
	std::ifstream jobsFile;
	JobEntry* nextJobEntry;
};

#endif /* SRC_XDEVS_DEVSJOBSOFFLINE_H_ */
