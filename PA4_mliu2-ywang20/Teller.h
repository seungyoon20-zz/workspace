/*
 * Teller.h
 *
 *  Created on: Feb 11, 2017
 *      Author: mliu2 ywang20
 */
#include "Event.h"
#include <cstdlib>
#ifndef TELLER_H_
#define TELLER_H_

class Teller : public Event{
public:
	Teller();
	virtual ~Teller();
	void setIdleTime(int cTime);
	void setServeTime(int avgSTime,int cTime);
	int  getServeTime();
	int  getIdleTime();
	void Action (int avgTime,bool isServ,int cTime);
	bool isTeller();
	void setNum(int n);
	bool isServ();
	int getNum();
private:
	int idleTime,serveTime,tellerNum;
	bool isService;
};

#endif /* TELLER_H_ */
