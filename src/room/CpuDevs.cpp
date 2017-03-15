/*
 * CpuDevs.cpp
 *
 *  Created on: 26 ene. 2017
 *      Author: fernando
 */

#include "CpuDevs.h"
// @todo Cpuid is just a patch,values for this cpu from solana-server cpu[0]
CpuDevs::CpuDevs(const std::string& name, int fanSpeed, double cpuPower, int cpuid):Atomic(name),
																	iFanSpeed(new Port(name+'_'+cpuid+'_'+"iFanSpeed")),
																	iCpuPower(new Port(name+'_'+cpuid+'_'+"iCpuPower")),
																	iUsedCpu(new Port(name+'_'+cpuid+'_'+"iUsedCpu")),
																	iInletTemp(new Port(name+'_'+cpuid+'_'+"iInletTemp")),
																	iAirflow(new Port(name+'_'+cpuid+'_'+"iAirflow")),
																	iFanPower(new Port(name+'_'+cpuid+'_'+"iFanPower")),
																	iMemPower(new Port(name+'_'+cpuid+'_'+"iMemPower")),
																	oTempCpu(new Port(name+'_'+cpuid+'_'+"oTempCpu")),
																	oPower(new Port(name+'_'+cpuid+'_'+"oPower")),
																	m_cpuid(cpuid){
	statusInfo=new unordered_map<string, double>();
	InletPorts=true;
	statusInfo["inlet"]= 22;
}

CpuDevs::~CpuDevs() {
	delete  iFanSpeed;
	delete	iCpuPower;
	delete	iUsedCpu;
	delete	iInletTemp;
	delete	iAirflow;
	delete	iFanPower;
	delete	iMemPower;
	delete	oTempCpu;
	delete  oPower;
	delete statusInfo;
}

void CpuDevs::initialize() {
	this->passivate();
}


void CpuDevs::deltint() {



}

void CpuDevs::deltext(double e) {
	Event event;
	if(Atomic::phaseIs("w84job")){}
	else if(Atomic::phaseIs("w84inlet")){
		if(!iInletTemp.isEmpty() && !InletPorts){
			InletPorts=true;
			event = iInletTemp.getSingleValue();
			statusInfo["inletTemp"]= (double*) event.getPtr();
			Atomic::holdIn("w84fan", 0.01);
		}
	}else if(Atomic::phaseIs("w84fan")){

	}else if(Atomic::phaseIs("w84disk")){

	}else if(Atomic::phaseIs("w84mem")){

	}
		if(!iMemPower.isEmpty() && !memPorts){
			diskPorts=true;
			event= iMemPower.getSingleValue();
			statusInfo["MemPower"]=(double*) event.getPtr();
			event= iFanSpeed.getSingleValue();
			statusInfo["FanSpeed"]=(int*) event.getPtr();
		}
		if(!iInletTemp.isEmpty() && !InletPorts){
			InletPorts=true;
		}
		if(!iInletTemp.isEmpty() && !InletPorts){
			InletPorts=true;
		}
	}


}

void lambda() {
	//Event event = Event::makeEvent<t_job>(job);
	//oOut.addValue(event);
}


