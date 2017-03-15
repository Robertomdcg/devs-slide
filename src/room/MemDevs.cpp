/*
 * MemDevs.cpp
 *
 *  Created on: 25/01/2017
 *      Author: roberto
 */

#include "MemDevs.h"

MemDevs::MemDevs(double memPower, const std::string& name): Atomic(name){
	this->iStart("start"+name);
	this->oOut("out"+name);
	this->addInPort(&iStart);
	this->addOutPort(&oOut);
	this->m_memPower=memPower;
	this->powerAux=0;
}

MemDevs::~MemDevs() {
}


void MemDevs::initialize(){
	this->passivate();
}

void MemDevs::exit() {
	this->passivate();
}

void MemDevs::deltint(){
		this->passivate();
}

void MemDevs::deltext(double e){
	Event newpower=iStart.getSingleValue();
	if(Atomic::phaseIs("passive")){
		m_memPower= *(newpower.getPtr());
		powerAux=m_memPower;
		this->holdIn("active", period);
	}else if(Atomic::phaseIs("active") || Atomic::phaseIs("interrupt")){
		accumE+=e;
		powerAux+=m_memPower*e;
		m_memPower= *(newpower.getPtr());
		this->holdIn("active", period-accumE);
	}
}

void MemDevs::lambda(){
	Event event = Event::makeEvent<double>(&m_memPower);
	oOut.addValue(event);
	std::cout << "Setting memPower "<< m_memPower<<" for ServerCoordinator from " << this->name << "at start";
}
