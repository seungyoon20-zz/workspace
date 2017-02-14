/*
 * Event.h
 *
 *  Created on: Feb 10, 2017
 *      Author: mingquan
 */

#ifndef EVENT_H_
#define EVENT_H_

class Event {
public:
	//Event(Event *prevEvent,Event *nextEvent);
	Event();
	virtual ~Event();
	virtual int getExTime();
	void setNextEvent(Event *nextEvent);
	void setPrevEvent(Event *PrevEvent);
	Event* getNextEvent();
	Event* getPrevEvent();
	void addEvent(Event *e);
	Event* getFirstEvent();
	Event* dequeue();
	void addWait(Event *e);
	int getLength();
	virtual void setExTime(int time);
	virtual bool isTeller();
	virtual int getIdleTime();
	virtual int getServeTime();
	virtual void Action(int timeRange,bool isServ,int cTime);
	virtual bool isServ();
	virtual int getNum();
	virtual void setNum(int n);
private:
	Event *prevEvent,*nextEvent;
	int exTime;
};

#endif /* EVENT_H_ */
