/*
 * MemDevs.h
 *
 *  Created on: 25/01/2017
 *      Author: roberto
 */

#ifndef SRC_XDEVS_MEMDEVS_H_
#define SRC_XDEVS_MEMDEVS_H_

#include <xdevs/core/modeling/Port.h>
#include <xdevs/core/modeling/Atomic.h>
#include <xdevs/core/modeling/Event.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace MemDevs;

class MemDevs: public Atomic, public ServerPart {
public:
	MemDevs(double memPower,const std::string& name);
	virtual ~MemDevs();

	// DEVS protocol
	virtual void initialize();
	virtual void exit();
	virtual void deltint();
	virtual void deltext(double e);
	virtual void lambda();
	Port iStart;
	Port oOut;

protected:
	double m_memPower;
	double powerAux;
};
#endif /* SRC_XDEVS_MEMDEVS_H_ */
