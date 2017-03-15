/*
 * IRCDevs.h
 *
 *  Created on: 03/12/2016
 *      Author: roberto
 */

#ifndef SRC_XDEVS_IRCDEVS_H_
#define SRC_XDEVS_IRCDEVS_H_

class IRCDevs: public Atomic {
public:
	IRCDevs();
	virtual ~IRCDevs();

	static const int DEFAULT_INLET_TEMPERATURE = 18;
	static const int NUM_GALLONS_SETTING = 5;
	// Setters and getters
	void setInletTemp(int temp);
	int getInletTemp();
    // Model computation
	virtual double computePower(double airflow) = 0;
	virtual double computeGallons(double airflow, double heatPower, double tempAirHot,
	                                  double tempWaterCold) = 0;
	virtual double computeHotWaterTemp(double waterFlow, double heatPower) = 0;
	virtual int getGallons(int idx) = 0;
    //Atomic methods
	virtual void deltint() = 0;
    virtual void deltext(double e) = 0;
	virtual void lambda() = 0;

	protected:
	    int m_inletTemp;
	    double m_tempWaterCold;
	};


#endif /* SRC_XDEVS_IRCDEVS_H_ */
