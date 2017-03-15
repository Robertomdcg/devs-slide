/*
 * DevsSlide.cpp
 *
 *  Created on: 13/07/2016
 *      Author: jlrisco
 */

#include "DevsSlide.h"

DevsSlide::DevsSlide(const std::string& name,
					 const std::string& jobsFilePath) : Coupled(name),
					 jobs("Jobs", jobsFilePath),
					 //weather("Weather", weatherJobsPath),
					 resource("resourceManager"),
					 transducer("transducer")

{
	//Coupled::addComponent(&weather);

	/*Coupled::addComponent(&processor);
	Coupled::addComponent(&transducer);
	Coupled::addCoupling(&generator, &generator.oOut, &processor, &processor.iIn);
	Coupled::addCoupling(&generator, &generator.oOut, &transducer, &transducer.iArrived);
	Coupled::addCoupling(&processor, &processor.oOut, &transducer, &transducer.iSolved);
	Coupled::addCoupling(&transducer, &transducer.oOut, &generator, &generator.iStop);*/
	Coupled::addComponent(&jobs);
	Coupled::addComponent(&transducer);
	Coupled::addComponent(&resource);
	Coupled::addCoupling(&jobs, &jobs.oOut, &resource, &resource.iJob);
	Coupled::addCoupling(&resource, &resource.oJob["oJob"], &transducer, &transducer.iJob);
}

DevsSlide::~DevsSlide() { }

