/*
 * server_commons.h
 *
 *  Created on: 06/03/2017
 *      Author: roberto
 */

#ifndef SRC_XDEVS_ROOM_SERVER_COMMONS_H_
#define SRC_XDEVS_ROOM_SERVER_COMMONS_H_


typedef struct{
	double dynPower;
	double idlePower;
}t_power;

typedef struct {
    bool begin;
    int jobId;
    time_t startTime;
    time_t endTime;
    int numProcs;   //! Number of processors allocated
}t_job;


#endif /* SRC_XDEVS_ROOM_SERVER_COMMONS_H_ */
