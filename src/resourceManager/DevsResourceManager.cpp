/*
 * DevsResourceManager.cpp
 *
 *  Created on: 13/03/2017
 *      Author: roberto
 */

#include "DevsResourceManager.h"

/*
DevsSlide::DevsSlide(const std::string& name,
		             const std::string& weatherFilePath,
					 const std::string& jobsFilePath) : Coupled(name),
													    weather("Weather", weatherFilePath),
														jobs("Jobs", jobsFilePath),
														{
	Coupled::addComponent(&weather);
	Coupled::addComponent(&jobs);
	Coupled::addComponent(&processor);
	Coupled::addComponent(&transducer);
	Coupled::addCoupling(&generator, &generator.oOut, &processor, &processor.iIn);
	Coupled::addCoupling(&generator, &generator.oOut, &transducer, &transducer.iArrived);
	Coupled::addCoupling(&processor, &processor.oOut, &transducer, &transducer.iSolved);
	Coupled::addCoupling(&transducer, &transducer.oOut, &generator, &generator.iStop);
}*/
DevsResourceManager::DevsResourceManager(const std::string& name):Coupled("resourceManager"),allocator("allocator", DevsAllocator::ALLOCPATH),iJob("iJob"),oJob(map<string,Port>()){
	oJob["oJob"]= Port("oJob");
	this->addInPort(&iJob);
	this->addOutPort(&oJob["oJob"]);
	Coupled::addComponent(&allocator);
	Coupled::addCoupling(this, &(this->iJob), &allocator, &allocator.iJob);
	Coupled::addCoupling(&allocator, &(allocator.oJob["oJob"]), this, &(this->oJob["oJob"]));
}

DevsResourceManager::~DevsResourceManager() {

}

