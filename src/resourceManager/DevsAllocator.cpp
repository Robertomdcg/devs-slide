/*
 * DevsAllocator.cpp
 *
 *  Created on: 13/03/2017
 *      Author: roberto
 */

#include "DevsAllocator.h"

//static string init
const string DevsAllocator::ALLOCPATH ="data/wkload/test-10job-alloc/alloc/slurm/files-default-slurm/";
const string DevsAllocator::ALLOCOUT_FILE_PREFIX = "alloc_out_";
const string DevsAllocator::ALLOCOUT_FILE_SUFFIX = ".txt";

const string DevsAllocator::JOBPARAM_FILE_PREFIX = "param_job_";
const string DevsAllocator::JOBPARAM_FILE_SUFFIX = ".txt";

DevsAllocator::DevsAllocator(const std::string& name, const std::string& jobsFilePath):
		Atomic(name), iJob("iJob"),oJob(map<string,Port>()),allocEvent(Event()),nextJobEntry(NULL),m_allocPath(jobsFilePath) {
	oJob["oJob"]= Port("oJob");
	this->addInPort(&iJob);
	this->addOutPort(&oJob["oJob"]);
}

DevsAllocator::~DevsAllocator() {
}

void DevsAllocator::initialize() {
		this->passivate();
}

void DevsAllocator::exit() {
}

void DevsAllocator::deltint() {
		this->passivate();
}
//TODO DELETE A LOS NUEVOS NEXT JOB ENTRY
void DevsAllocator::deltext(double e) {
	if (Atomic::phaseIs("passive")) {
			allocEvent = this->iJob.getSingleValue();
			JobEntry jE= *(JobEntry*)allocEvent.getPtr();
			nextJobEntry= new JobEntry();
			nextJobEntry->begin=jE.begin;
			nextJobEntry->cpuPower=jE.cpuPower;
			nextJobEntry->id=jE.id;
			bool wrong=false;
			string opening = m_allocPath+DevsAllocator::ALLOCOUT_FILE_PREFIX+std::to_string(nextJobEntry->id)+DevsAllocator::ALLOCOUT_FILE_SUFFIX;
			cout << opening << endl;
			ifstream alloc_out(m_allocPath+DevsAllocator::ALLOCOUT_FILE_PREFIX+std::to_string(nextJobEntry->id)+DevsAllocator::ALLOCOUT_FILE_SUFFIX);
			if(!getNextAllocParam(alloc_out, nextJobEntry->ircName, nextJobEntry->serverName, nextJobEntry->numThreads)){
				std::cerr << "Alloc params not defined for "<< nextJobEntry->id << std::endl;
				this->passivate();
				wrong=true;
			}
			alloc_out.close();
			ifstream job_param(m_allocPath+ DevsAllocator::JOBPARAM_FILE_PREFIX+ std::to_string(nextJobEntry->id)+ DevsAllocator::JOBPARAM_FILE_SUFFIX);
			if(!getNextJobParam(job_param,nextJobEntry->numCores, nextJobEntry->cpuPower, nextJobEntry->memPower)){
				std::cerr << "Job parameters not defined for "<< nextJobEntry->id << std::endl;
				this->passivate();
				wrong=true;
			}
			job_param.close();
			if(!wrong)
				Atomic::holdIn("gotJob", 0);
	}
}

void DevsAllocator::lambda() {
	Event event = Event::makeEvent<JobEntry>(nextJobEntry);
	oJob["oJob"].addValue(event);
	std::cout << "Output event with time = " << nextJobEntry->time << std::endl;
}

bool DevsAllocator::getNextAllocParam(ifstream& allocFile, string& ircName, string&  serverName, string&  numThreads) {
	if(!allocFile.eof()) {
		std::getline(allocFile, ircName, ',');
		std::getline(allocFile, serverName, ',');
		std::getline(allocFile, numThreads);
		if(ircName.size()>0 && serverName.size()>0 && numThreads.size()>0) {
			ircName = ircName.substr(2,ircName.size()-3);
			serverName = serverName.substr(1,serverName.size()-2);
			numThreads = numThreads.substr(0,numThreads.size()-1);
			return true;
		}
	}
	return false;
}

bool DevsAllocator::getNextJobParam(std::ifstream& paramFilePath, std::string& numCores, std::string& cpuPower, std::string& memPower) {
	if(!paramFilePath.eof()) {
		std::getline(paramFilePath, numCores, ',');
		std::getline(paramFilePath, cpuPower, ',');
		std::getline(paramFilePath, memPower, ',');
		if(numCores.size()>0 && cpuPower.size()>0 && memPower.size()>0) {
			numCores = numCores.substr(1,numCores.size()-1);
			memPower = memPower.substr(0,memPower.size()-1);
			return true;
		}
	}
	return false;
}
