/*
 * Customer.h
 *
 *  Created on: Feb 10, 2017
 *      Author: mingquan
 */
#include <cstdlib>
#include "Event.h"
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
class Event;
class Customer: public Event {
public:
	//Customer(Event *prevEvent,Event *nextEvent);
	Customer();
	virtual ~Customer();
	void setArrivalTime(int timeRange);   // for the arrival case
	void setServiceTime(int ExTime);	  	//   set the execution time for
	void setSTIme(int sTime);
	int  getWTime(int cTime);
	void Action(int time,bool isServ,int cTime);
	bool isTeller();
	bool isServ();
	void setCTime(int t);
	int getCTime();
	int getTimeD();
	void setNum(int i);
	int getNum();
private:
	int sTime,cTime,cusNumber;          					// The start time for waiting time;
	bool isService;
};

#endif /* CUSTOMER_H_ */
