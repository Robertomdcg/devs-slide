/*
 * DevsAllocator.h
 *
 *  Created on: 13/03/2017
 *      Author: roberto
 */

#ifndef SRC_XDEVS_RESOURCEMANAGER_DEVSALLOCATOR_H_
#define SRC_XDEVS_RESOURCEMANAGER_DEVSALLOCATOR_H_


#include "../core/modeling/Port.h"
#include "../core/modeling/Atomic.h"
#include "../core/modeling/Event.h"
#include "../commons.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class DevsAllocator: public Atomic {
public:


    static const int FIRST_JOB_ID = 1001;
    static const int EXIT_CODE = 0;
    static const int NEXT_CODE = 1;

    static const string ALLOCPATH;
    static const string ALLOCOUT_FILE_PREFIX;
    static const string ALLOCOUT_FILE_SUFFIX;

    static const string JOBPARAM_FILE_PREFIX;
    static const string JOBPARAM_FILE_SUFFIX;

    //que es esto? static constexpr char CURRENT_ALLOC_FILE[] = "/tmp/prev_alloc.txt";

	Port iJob;
	map<string,Port> oJob;
	DevsAllocator(const std::string& name, const std::string& jobsFilePath);
	virtual ~DevsAllocator();

	// DEVS protocol
	virtual void initialize();
	virtual void exit();
	virtual void deltint();
	virtual void deltext(double e);
	virtual void lambda();

protected:
	bool getNextAllocParam(ifstream& allocFile, string& ircName, string&  serverName,string&  numThreads);
	bool getNextJobParam(ifstream& paramFilePath, string& numCores, string& cpuPower, string& memPower);
	Event allocEvent;
	JobEntry* nextJobEntry;
	std::string m_allocPath;
};

#endif /* SRC_XDEVS_RESOURCEMANAGER_DEVSALLOCATOR_H_ */
