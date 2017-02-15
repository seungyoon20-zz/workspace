/*
 * Teller.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: mliu2 ywang20
 */

#include "Teller.h"
#include <iostream>
using namespace std;
//private int idleTime,serveTime;
Teller::Teller() {
	// TODO Auto-generated constructor stub
tellerNum =0;
isService= false;
idleTime =0;
serveTime=0;
}

Teller::~Teller() {
	// TODO Auto-generated destructor stub
	//~Event();
}

void Teller::setIdleTime(int cTime){      // set the EldleTime as the 1-150  and set the Extime to be cTime plus idleTime
  idleTime = int(149*float(rand())/float(RAND_MAX))+1;

  setExTime(cTime+idleTime);
}

void Teller::setServeTime(int avgTime,int cTime)   // set the service time to be range from 1 to 2*avgTime and set the exTime to be cTime plus serveTime
{
	serveTime = int((2*avgTime)*float(rand())/float(RAND_MAX));
	setExTime(cTime+serveTime);
}

int  Teller::getIdleTime(){ 						// return the idleTime
	return idleTime;
}

int  Teller::getServeTime(){						// return the serveTime
	return serveTime;
}

void Teller::Action(int avgTime,bool isServ,int cTime){
	isService = isServ;
	if(isServ) setServeTime(avgTime,cTime);
	else
		setIdleTime(cTime);

}
void Teller::setNum(int n)
{
	tellerNum = n;
}
bool Teller::isTeller(){
	return true;
}
bool Teller::isServ(){
	return isService;
}
int Teller::getNum(){
	return tellerNum;
}
