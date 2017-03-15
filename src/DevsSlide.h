/*
 * DevsSlide.h
 *
 *  Created on: 13/07/2016
 *      Author: jlrisco
 */

#ifndef SRC_XDEVS_DEVSSLIDE_H_
#define SRC_XDEVS_DEVSSLIDE_H_

#include "core/modeling/Coupled.h"

//#include "DevsWeather.h"
#include "DevsJobsOffline.h"
#include "test/DevsTransducer.h"
#include "resourceManager/DevsResourceManager.h"
#include <iostream>

class DevsSlide : public Coupled {
protected:
	//DevsWeather weather;
	DevsJobsOffline jobs;
	//RoomDevs room;
	DevsResourceManager resource;
	DevsTransducer transducer;

public:
	DevsSlide(const std::string& name,
			//const std::string& weatherFilePath,
			const std::string& jobsFilePath);
	virtual ~DevsSlide();
};

#endif /* SRC_XDEVS_DEVSSLIDE_H_ */
