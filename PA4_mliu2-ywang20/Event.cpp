/*
 * Event.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: mliu2 ywang20
 */
#include <iostream>
#include "Event.h"

//private Event *prevEvent,*nextEvent;  // set up the linked list property of the event list.
//private int exTime;

using namespace std;
Event::Event(){
	exTime =0;
	prevEvent =0;
	nextEvent =0;
}
//Event::Event(Event *prevEvent,Event *nextEvent) {
//	// TODO Auto-generated constructor stub
//	this->prevEvent = prevEvent;
//	this->nextEvent = nextEvent;
//
//}
//Delete the whole tow events connect
Event::~Event() {
	// TODO Auto-generated destructor stub
	delete[] prevEvent;
	delete[] nextEvent;
}

void Event:: setNextEvent(Event *nextEvent){     //Change the nextEvent
	this->nextEvent = nextEvent;
}
void Event::setPrevEvent(Event *prevEvent){		// change the prevEvent
	this->prevEvent = prevEvent;
}

Event* Event::getNextEvent(){					//get the nextEvent
		return nextEvent;
	}
Event* Event:: getPrevEvent(){					// get the prevEvent
		return prevEvent;
	}

void Event::addEvent(Event *e){		//add the event from the beginning of the list
	Event *a = e;
	if(a->getExTime()<= exTime){
		if(prevEvent!=0)
		{
			prevEvent->setNextEvent(a);
			a->setPrevEvent(prevEvent);
		}
		prevEvent = a;
		a->setNextEvent(this);
	}
	else
		if(nextEvent ==0)
		{
		 nextEvent = a;
		 a->setPrevEvent(this);
		}
		else
			nextEvent->addEvent(a);
	}



void Event::setExTime(int time){     			// set the execution time
 exTime = time;
}

int Event::getExTime(){							// set the execution time
	return exTime;
}

Event* Event::getFirstEvent(){                  // find the first event;
	if(prevEvent ==0)
		return this;
	else
		return prevEvent->getFirstEvent();

}

Event* Event::dequeue(){						// will return the second node.
	Event* a = getFirstEvent();
	Event* b = a->getNextEvent();
	if(b!=0)
	{
	a->setNextEvent(0);
	b->setPrevEvent(0);
	return b;
	}
	else{
 	     return 0;
	}

}
int Event::getLength(){							// get the length from this specific event
	int count =0;
	Event* a = nextEvent;
	while(a!=0)
	{
		count++;
		a = a->getNextEvent();
	}
	//delete []a;
	return count;
}
 void Event::Action(int timeRange,bool isServ,int cTime){
}

 bool Event::isTeller(){
	 return false;
 }
 int Event::getIdleTime(){
	 return 0;
 }
 int Event::getServeTime(){
	 return 0;
 }

 bool Event::isServ(){
return false;
 }
 int Event::getNum(){
	 return 0;
 }

 void Event::setNum(int t){

 }
//void Event::Action(int timeRange,bool isServ,int cTtime){
//
//}
