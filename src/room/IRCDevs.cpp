/*
 * IRCDevs.cpp
 *
 *  Created on: 03/12/2016
 *      Author: roberto
 */

#include "IRCDevs.h"

IRCDevs::IRCDevs() {
	m_inletTemp=DEFAULT_INLET_TEMPERATURE;
}

IRCDevs::~IRCDevs() {

}

void IRC::setInletTemp(int temp)
{
    m_inletTemp=temp;
}

int IRC::getInletTemp()
{
    return m_inletTemp;
}

