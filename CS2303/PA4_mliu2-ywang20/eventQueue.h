/*
 * eventQueue.h
 *
 *  Created on: Feb 13, 2017
 *      Author: mliu2 ywang20
 */
#include "Event.h"
#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

class eventQueue {
public:
	eventQueue();
	virtual ~eventQueue();
    
	Event* head;
    
	void addEvent(Event* e);
	bool isEmpty();
	bool isTeller();
	bool isServ();
	int getExTime();
	void dequeue();
	Event* getHead();
	void inServeC();
	int getServeC();
	int getNum();
	bool hasCus();

private:
	int serveC;

};

#endif /* EVENTQUEUE_H_ */
