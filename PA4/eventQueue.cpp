/*
 * eventQueue.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: mingquan
 */

#include "eventQueue.h"

eventQueue::eventQueue() {
	// TODO Auto-generated constructor stub
	head = 0;
	serveC=0;
}

eventQueue::~eventQueue() {
	// TODO Auto-generated destructor stub
	delete[] head;
}

void eventQueue::addEvent(Event* e)
{
	Event* a =e;
	head->addEvent(a);
	head = a->getFirstEvent();

}

bool eventQueue::isEmpty(){
	if(head ==0) return true;
	else
		return false;
}

Event* eventQueue::getHead(){
	return head;
}

bool eventQueue::isTeller(){
	return head->isTeller();
}
bool eventQueue::isServ(){
	return head->isServ();
}
void eventQueue::dequeue(){
	head = head->dequeue();
}

int eventQueue::getExTime(){
	return head->getExTime();
}

void eventQueue::inServeC(){
	serveC++;
}
int eventQueue::getServeC(){
	return serveC;
}

int eventQueue::getNum(){
	return head->getNum();
}

bool eventQueue::hasCus(){
	Event* a =head;
	while(a->getNextEvent()!=0){
		if(!a->isTeller()) return true;
		a = a->getNextEvent();
	}
	return false;
}

//void eventQueue::setHead(){
//	head
//}
