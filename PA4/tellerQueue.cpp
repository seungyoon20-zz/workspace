/*
 * tellerQueue.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: mingquan
 */

#include "tellerQueue.h"

tellerQueue::tellerQueue() {
	// TODO Auto-generated constructor stub
	waitingList =0;
	tellerNum =0;

}

tellerQueue::~tellerQueue() {
	// TODO Auto-generated destructor stub
	delete[] waitingList;
}

Event* tellerQueue::getList(){
	return waitingList;
}

int tellerQueue::getNum(){
	return waitingList->getNum();
}

void tellerQueue::setNum(int n){
	tellerNum =n;
}

void tellerQueue::addEvent(Event* e){
	waitingList->addEvent(e);
}

bool tellerQueue::isEmpty(){
	if(waitingList ==0) return true;
	else
		return false;
}

void tellerQueue::dequeue(){
	waitingList = waitingList->dequeue();
}

int tellerQueue::getExTime(){
	return waitingList->getExTime();
}

void tellerQueue::setHead(Event* e){
	 waitingList= e;
}

int tellerQueue::getLength(){
	return waitingList->getLength();
}
