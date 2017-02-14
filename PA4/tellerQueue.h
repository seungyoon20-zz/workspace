/*
 * tellerQueue.h
 *
 *  Created on: Feb 13, 2017
 *      Author: mingquan
 */
#include"Event.h"
#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_

class tellerQueue {
public:
	tellerQueue();
	virtual ~tellerQueue();
	Event* getList();
	int getNum();
	void addEvent(Event* e);
	bool isEmpty();
	int getExTime();
	void dequeue();
	void setNum(int n);
	void setHead(Event* e);
	int getLength();
private:
	Event *waitingList;
	int tellerNum;
};

#endif /* TELLERQUEUE_H_ */
