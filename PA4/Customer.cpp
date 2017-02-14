/*
 * Customer.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: mingquan
 */
//#include <cstdlib>
#include "Customer.h"
//#include "Event.h"
#include <iostream>
using namespace std;
//private sTime;
Customer::Customer(){
	sTime =0;
	isService = false;
	cTime=0;
	cusNumber =0;
}
//Customer::Customer(Event *prevEvent,Event *nextEvent) {
//	Event(prevEvent,nextEvent);
//	sTime =0;
//	// TODO Auto-generated constructor stub
//
//}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
	//~Event();
}

int Customer::getWTime(int cTime){    // Return the wait time for the wait time in line
	return cTime-sTime;
}

void Customer::setSTIme(int sTIme){		// set the start time of the waiting line.
	this->sTime =sTime;
}

void Customer::setServiceTime(int exTime){  // Set the execution time for the service
	setExTime(exTime);
}

void Customer::setArrivalTime(int timeRange){  // set the arrival time for the customer  the time range is in secomds
	setExTime(int(timeRange*float(rand()/float(RAND_MAX))));
}

 void Customer::Action(int time,bool isServ,int cTime){
	 this->cTime = cTime;
	 isService = isServ;
	if(isService)
		setServiceTime(time+cTime);
	else
		setArrivalTime(time);

}

 bool Customer::isTeller(){
	 return false;
 }

 bool Customer::isServ(){
	 return isService;
 }

 void Customer::setCTime(int t){
	 cTime =t;
 }

 int Customer::getCTime(){
	 return cTime;
 }

 int Customer::getTimeD(){					// get the Time difference.
	 return getExTime()-cTime;
 }

 void Customer::setNum(int n){
	 cusNumber =n;
 }
 int Customer::getNum(){
	 return cusNumber;
 }
