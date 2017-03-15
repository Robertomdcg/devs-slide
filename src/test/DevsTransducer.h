/*
 * DevsTransducer.h
 *
 *  Created on: 14/03/2017
 *      Author: roberto
 */

#ifndef SRC_XDEVS_TEST_DEVSTRANSDUCER_H_
#define SRC_XDEVS_TEST_DEVSTRANSDUCER_H_

#include "../core/modeling/Atomic.h"
#include "../commons.h"

using namespace std;

class DevsTransducer: public Atomic {
public:
	DevsTransducer(const std::string name);
	Port iJob;
	virtual ~DevsTransducer();

	// DEVS protocol
	virtual void initialize();
	virtual void exit();
	virtual void deltint();
	virtual void deltext(double e);
	virtual void lambda();

};

#endif /* SRC_XDEVS_TEST_DEVSTRANSDUCER_H_ */
