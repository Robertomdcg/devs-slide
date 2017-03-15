/*
 * CpuDevs.h
 *
 *  Created on: 26 ene. 2017
 *      Author: fernando
 */

#ifndef DEVS_SLIDE_SRC_XDEVS_CPUDEVS_H_
#define DEVS_SLIDE_SRC_XDEVS_CPUDEVS_H_

#include <xdevs/core/modeling/Port.h>
#include <xdevs/core/modeling/Atomic.h>
#include <xdevs/core/modeling/Event.h>
#include "server_commons.h"
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class CpuDevs: public Atomic {
public:

	CpuDevs(const std::string& name, int fanSpeed, double cpuPower,int cpuid);

	Port iInletTemp;
    Port iAirflow;
	Port iFanPower;
	Port iMemPower;
	Port iFanSpeed;
	Port iCpuPower;
	Port iUsedCpu;
	Port oPower;
	Port oTempCpu;
	//mm

	virtual ~CpuDevs();

	void cucu(){}
protected:
	//Constantes correspondientes a solana-server.
    static const int MAX_CPU_TEMP = 87;

    static const int NUM_FAN_SPEED = 5; // low, med-low, med, med-high, high
    static const int IDLE_POWER = 440;
    static const int DEFAULT_FAN_SPEED = 2400;
    static const int MODEL_TINLET = 22;
    static const int MIN_TIN_TOUT_DIFF = 14;
    static const int CPU0_IDLE_POWER = 58.3;
    static const int CPU1_IDLE_POWER = 61.6;

    // Model LUTs
    //XXX-marina: NUM_FAN_SPEED needs to be equal for all servers,
    // and is defined in server.hh
    static constexpr int fanSpeedLUT[NUM_FAN_SPEED] {
        //1800, 2100, 2400, 2700, 3000, 3300, 3600, 3900, 4200
        1800, 2400, 3000, 3600, 4200
    };

    static constexpr double fanPowerLUT[NUM_FAN_SPEED] {
        //9.32, 11.86, 14.73, 18.43, 22.34, 27.72, 33.39, 38.69, 46.33
        9.32, 14.73, 22.34, 33.39, 46.33

    };

    static constexpr double tempCpu0LUT[NUM_FAN_SPEED][2] {
        {58.1, 0.5718}, {50.5, 0.4063},
        {46.9, 0.3115},
        {45.4, 0.2708}, {44.2, 0.2472}
    };

    static constexpr double tempCpu1LUT[NUM_FAN_SPEED][2] {
        {56.5, 0.5120}, {48.4, 0.3618},
        {45.3, 0.2645},
        {44.1, 0.2233}, {42.4, 0.1997}
    };

    static const double W84JOB_TIME=0.1;
    static const double W84FAN_TIME=0.1;
    static const double W84DISK_TIME=0.1;
    static const double W84MEM_TIME=0.1;
    static const double SENTTOFS_TIME=0.1;
    static const double DOING_JOB_TIME=0.1;

    int m_cpuid;

    bool fanPorts=false;
    bool diskPorts=false;
    bool memPorts=false;
    bool InletPorts=false;

    unordered_map<string, double> statusInfo;

    void deltint();
    void deltext(double e);
    void initialize();

};

#endif /* DEVS_SLIDE_SRC_XDEVS_CPUDEVS_H_ */
