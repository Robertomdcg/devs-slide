/*
 * DevsTransducer.cpp
 *
 *  Created on: 14/03/2017
 *      Author: roberto
 */

#include "DevsTransducer.h"

DevsTransducer::DevsTransducer(const std::string name):Atomic("transducer") {
	this->addInPort(&iJob);

}

DevsTransducer::~DevsTransducer() {
}

void DevsTransducer::initialize() {
		this->passivate();
}

void DevsTransducer::exit() {
}

void DevsTransducer::deltint() {
	this->passivate();
}

void DevsTransducer::deltext(double e) {
	Event allocEvent = this->iJob.getSingleValue();
	JobEntry jE= *(JobEntry*)allocEvent.getPtr();
	jobToString(jE);
	this->passivate();
}

void DevsTransducer::lambda() {
}
