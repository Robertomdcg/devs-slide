/*
 * DevsResourceManager.h
 *
 *  Created on: 13/03/2017
 *      Author: roberto
 */

#ifndef SRC_XDEVS_RESOURCEMANAGER_DEVSRESOURCEMANAGER_H_
#define SRC_XDEVS_RESOURCEMANAGER_DEVSRESOURCEMANAGER_H_

#include "DevsAllocator.h"
#include "../core/modeling/Coupled.h"

class DevsResourceManager: public Coupled {
protected:
	DevsAllocator allocator;
public:
	DevsResourceManager(const std::string& name);
	virtual ~DevsResourceManager();
	Port iJob;
	map<string,Port> oJob;
};


#endif /* SRC_XDEVS_RESOURCEMANAGER_DEVSRESOURCEMANAGER_H_ */
