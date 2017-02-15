
#include "Teller.h"
#include "Event.h"
#include "Customer.h"
#include "eventQueue.h"
#include "tellerQueue.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
/*This is the formal bank model which will produce the bank model based on the command line input.
 *
 */
int timeRange,avgTime,numCus,numTell,cTime,seed;
float avgTimeM;
Event *lastEvent;
int getShortestWaitingLine(tellerQueue* w[],int length);
float getSTD(int a[][2],int row,float avg);
int randomSelectLine(tellerQueue* w[],int length);

int main (int argc, char* argv[]){
	eventQueue *head = new eventQueue();
	cTime =0;
	seed = time(0);

	if(argc<4) {
		cout << "You have wrong command line input";
		//exit(-1);
	}
	else
	{
	 numCus = atoi(argv[1]);
	 numTell = atoi(argv[2]);
	 timeRange =atoi(argv[3]);
	 avgTimeM = atof(argv[4]);
	 if(argc>5){
		 seed = atoi(argv[5]);
	 }
	}
	srand(seed);
	timeRange = timeRange*60;		//Change the Time range from minutes to seconds.
	avgTime =(int)(avgTimeM*60);   	//change avgTime from float minutes to int seconds
	cout <<avgTime <<endl <<timeRange<<endl;
	   tellerQueue *waitingList[numTell]; // Creating
	   int TellerData[numTell][2];		// Create an array of integer to record the teller's data for serving and idling. TellerData[][0] for serving time and TellerData[][1] for idle time
	   int customerData[numCus][2];
									//Setting up the bank model right now.
    //i is always in range[0,numCus), each time initiates a customer of index i, set the index of the customer class, call action function, and add the cutomer to the eventQueue. Then +=1 to jump to the next index until touch the bound.
	for(int i=0;i<numCus;i++){					// Build up the event list
		Customer *a = new Customer();
		a->setNum(i);
		a->Action(timeRange,false,0);
		if(head->isEmpty()) head->head=a;
		else
			head->addEvent(a);
		customerData[i][0]=0;
		customerData[i][1]=0;
	}
    //i is always in range[0,numTeller), each time initiates a teller of index i, set the index of the teller class, call action function, and add the teller to the eventQueue. Then +=1 to jump to the next index until touch the bound.
   for(int i=0;i<numTell;i++){					// Add teller event to the beginning of the
	   waitingList[i]=new tellerQueue();
	   Teller *a = new Teller();
	   a->setExTime(0);
	   a->setNum(i);
	   head->addEvent(a);
	   TellerData[i][0]=0;
	   TellerData[i][1]=0;
   }
    
    //The while-loop continues when there is still event in the eventQueue waiting to be dequeue. Each time do the head and dequeue the head.
   while(!head->isEmpty()){								// running the event queue
	   cTime = head->getExTime();				// Update the current time
	   if(head->isTeller()){

		   int num = head->getNum();			// record the teller number


		   if(!waitingList[num]->isEmpty()){				// The case for when there is someone in front of you
			   Teller *t = new Teller();
			   Customer *c = new Customer();
			   t->setNum(num);
			   int cusNum = waitingList[num]->getNum();
			   c->setNum(cusNum);
			   t->Action(avgTime,true,cTime);	// set up the service time
			   int serveT = t->getServeTime();
			   int wTime = cTime-waitingList[num]->getExTime();
			   c->Action(serveT,true,cTime);
			   head->addEvent(t);

			   head->addEvent(c);
			   head->inServeC();
			   waitingList[num]->dequeue();     // move the waiting list
			   TellerData[num][0] = TellerData[num][0]+serveT;		// update the teller data.
			   customerData[cusNum][0]=customerData[cusNum][0]+serveT;
			   customerData[cusNum][1]=customerData[cusNum][1]+wTime;

		   }
		   else									// for the shortest line of others
		   {
			   int tNum = randomSelectLine(waitingList,numTell);
			   if(tNum==-1){			//The case for the idle time
				   if(head->hasCus())						//When there is still customer coming add idling
				   {
					   Teller* t = new Teller();
					   t->setNum(num);
					   t->Action(0,false,cTime);
					   int idleTime = t->getIdleTime();
					   TellerData[num][1] = TellerData[num][1]+idleTime;		// update the teller data.
					   head->addEvent(t);
				   }
			   }
			   else												// for the case of getting from the shortest line.
			   {
				   Teller *t = new Teller();
				   Customer *c = new Customer();
				   int cusNum = waitingList[tNum]->getNum();
				   c->setNum(cusNum);
				   t->setNum(num);
				   t->Action(avgTime,true,cTime);	// set up the service time
				   int serveT = t->getServeTime();
				   int wTime = cTime-waitingList[tNum]->getExTime();
				   c->Action(serveT,true,cTime);
				   head->addEvent(t);
				   head->addEvent(c);
				   waitingList[tNum]->dequeue();
				   head->inServeC();					// increase the service number
				   TellerData[num][0] = TellerData[num][0]+serveT;		// update the teller data.
				   customerData[cusNum][0]=customerData[cusNum][0]+serveT;
				   customerData[cusNum][1]=customerData[cusNum][1]+wTime;
			   }
		   }
	   }
	   else
	   {
		   if(!head->isServ())
		   {

		   int tNum = getShortestWaitingLine(waitingList,numTell);
		   Customer* c = new Customer();
		   int cusNum = head->getNum();
		   c->setNum(cusNum);
		   c->setExTime(cTime);
		   	   if(waitingList[tNum]->isEmpty())
		   	   {
			   waitingList[tNum]->setHead(c);
		   	   }
		   	   else
		   		   waitingList[tNum]->addEvent(c);
		   }
	   }

	    head->dequeue();
   }
   int totalServeTime =0;
   int totalServeTimeC =0;
   int totalIdleTime =0;
   int maxWaitTime =0;
   int totalSpendT=0;
   float avgT =0;
   float std =0;
   for(int i=0;i<numTell;i++){
	   cout<< "The Teller "<<i<<" serves "<<TellerData[i][0]<<" seconds and ildes " <<TellerData[i][1]<<endl;
	   totalServeTime+= TellerData[i][0];
	   totalIdleTime+= TellerData[i][1];
   }
   for(int i=0;i<numCus;i++){
//	   cout<< "The Customer "<<i<<" has service "<<customerData[i][0]<<" seconds and waits " <<customerData[i][1]<<endl;
	   totalServeTimeC+= customerData[i][0];
	   if(customerData[i][1]>maxWaitTime) maxWaitTime = customerData[i][1];
	   totalSpendT = totalSpendT+customerData[i][0]+customerData[i][1];
   }
	avgT =float(totalSpendT/head->getServeC());
	std =getSTD(customerData,numCus,avgT);
	cout <<endl<< "Number of customers served "<<head->getServeC()<<endl;
	cout << "Total time required to serve customers: "<<totalServeTimeC<<endl;
	cout <<"Average Time spend by customer: "<<avgT<<" and STD is "<<std<<endl;
	cout <<"Number of tellers : "<<numTell<<endl;
	cout<<"Multiple lines."<<endl;
	cout<< "Maximum wait time for a customer: "<<maxWaitTime<<endl;
	cout<<"Total service time : "<<totalServeTime<<"  Total idle time: "<<totalIdleTime<<endl<<endl;


	/**************************************************************************************************
	 * *********************************************************for the common line********************************************************************
	 *********************************************************************************************************/
	head = new eventQueue();
    //i is always in range[0,numCus), each time initiates a customer of index i, set the index of the customer class, call action function, and add the cutomer to the eventQueue. Reset the data in the customerData. Then +=1 to jump to the next index until touch the bound.
	for(int i=0;i<numCus;i++){					// Build up the event list
		Customer *a = new Customer();
		a->setNum(i);
		a->Action(timeRange,false,0);
		if(head->isEmpty()) head->head=a;
		else
			head->addEvent(a);
		customerData[i][0]=0;
		customerData[i][1]=0;
	}

	cTime =0;
	srand(seed);
	tellerQueue *commonLine = new tellerQueue();
    
    //i is always in range[0,numTeller), each time initiates a teller of index i, set the index of the teller class, call action function, and add the teller to the eventQueue. Reset the data in the TellerData. Then +=1 to jump to the next index until touch the bound.
	   for(int i=0;i<numTell;i++){					// Add teller event to the beginning of the
		   Teller *a = new Teller();
		   a->setExTime(0);
		   a->setNum(i);
		   head->addEvent(a);
		   TellerData[i][0]=0;
		   TellerData[i][1]=0;
	   }
    
        //The while-loop continues when there is still event in the eventQueue waiting to be dequeue. Each time do the head and dequeue the head.
	   while(!head->isEmpty()){								// running the event queue
		   cTime = head->getExTime();				// Update the current time
		   if(head->isTeller()){

			   int num = head->getNum();			// record the teller number


			   if(!commonLine->isEmpty()){				// The case for when there is someone in front of you
				   Teller *t = new Teller();
				   Customer *c = new Customer();
				   t->setNum(num);
				   int cusNum = commonLine->getNum();
				   c->setNum(cusNum);
				   t->Action(avgTime,true,cTime);	// set up the service time
				   int serveT = t->getServeTime();
				   int wTime = cTime-commonLine->getExTime();
				   c->Action(serveT,true,cTime);
				   head->addEvent(t);
				   head->addEvent(c);
				   commonLine->dequeue();     // move the waiting list
				   head->inServeC();
				   TellerData[num][0] = TellerData[num][0]+serveT;		// update the teller data.
				   customerData[cusNum][0]=customerData[cusNum][0]+serveT;
				   customerData[cusNum][1]=customerData[cusNum][1]+wTime;

			   }
			   else									// for the shortest line of others
			   {
				   if(head->hasCus())
				   {
					  Teller* t = new Teller();
					  t->setNum(num);
					  t->Action(0,false,cTime);
					  int idleTime = t->getIdleTime();
					  TellerData[num][1] = TellerData[num][1]+idleTime;		// update the teller data.
					  head->addEvent(t);
					  //cout << cTime<<" Idle "<<idleTime<<endl;
//					  delete[] t;
				   }
			   }
		   }
		   else
		   {
			   if(!head->isServ())
			   {
	//		   cout<<"Customer comes at "<<head->isTeller()<<endl;
	//		   cout<<"Customer comes at "<<cTime<<endl;
			   Customer *c = new Customer();
			   int cusNum = head->getNum();
			   c->setNum(cusNum);
			   c->setExTime(cTime);
			   	   if(commonLine->isEmpty())
			   	   {
				   commonLine->setHead(c);
			   	   }
			   	   else
			   		   commonLine->addEvent(c);

				  // delete[] c;
			   }

		   }

		    head->dequeue();
	   }

	   int totalServeTime2 =0;
	   int totalServeTimeC2 =0;
	   int totalIdleTime2 =0;
	   int maxWaitTime2 =0;
	   int totalSpendT2=0;
	   float avgT2 =0;
	   float std2 =0;
	   for(int i=0;i<numTell;i++){
		   cout<< "The Teller "<<i<<" serves "<<TellerData[i][0]<<" seconds and ildes " <<TellerData[i][1]<<endl;
		   totalServeTime2+= TellerData[i][0];
		   totalIdleTime2+= TellerData[i][1];
	   }
	   for(int i=0;i<numCus;i++){
		   totalServeTimeC2+= customerData[i][0];
		   if(customerData[i][1]>maxWaitTime2) maxWaitTime2 = customerData[i][1];
		   totalSpendT2 = totalSpendT2+customerData[i][0]+customerData[i][1];
	   }
	   avgT2 =float(totalSpendT2/head->getServeC());
	   std2 =getSTD(customerData,numCus,avgT2);
		cout <<endl<< "Number of customers served "<<head->getServeC()<<endl;
		cout << "Total time required to serve customers: "<<totalServeTimeC2<<endl;
		cout <<"Average Time spend by customer: "<<avgT2<<" and STD is "<<std2<<endl;
		cout <<"Number of tellers : "<<numTell<<endl;
		cout<<"Common line."<<endl;
		cout<< "Maximum wait time for a customer: "<<maxWaitTime2<<endl;
		cout<<"Total service time : "<<totalServeTime2<<"  Total idle time: "<<totalIdleTime2<<endl<<endl;

//		delete[] commonLine;

}



int getShortestWaitingLine(tellerQueue* w[],int length){	//find the shortest line in the waiting list
	 int l=w[0]->getLength();
	int tNum =0;
	int count =0;
    
    //Each time check the line length of the teller of index i, if the length of line i is shorter than the previous shortest line, set i as the shortest line index. Loop until touch the bound. Always get the index of the first one if there are several shortest lines.
	for(int i=0;i<length;i++){
		 int len =w[i]->getLength();
		if(len<l){
			l =len;
			tNum=i;
		}
	}
    //check how many shortest lines are in the entire bank, if the line of index i has a same length as the shortest line, add one to the count.
	for(int i =0;i<length;i++){
		if(w[i]->getLength()==l)count++;
	}
    
    //If there is only one shortest line, return its idex, otherwise create a array of integer and of size count to hold all the indexes of the shortest lines. Each time check if the line is of same length with the shortest line, if so, add the index to the array.
	if(count==1)
		return tNum;
	else
	{
		int a[count];
		count=0;
		for(int i=0;i<length;i++){
			if(w[i]->getLength()==l) {
				a[count]=i;
				count++;
			}
		}
	int c = int(rand()%count);
	return a[c];

	}
	return 0;
}

float getSTD(int a[][2],int row,float avg){
	float s = 0;
	for(int i=0;i<row;i++)
	{
		int sum=0;
		for(int j=0;j<2;j++)
		{
			sum = sum+a[i][j];
		}
		s= s+float(sum-avg)*float(sum-avg);
	}
	s=float(s/row);
	s = sqrt(s);
	return s;
}

int randomSelectLine(tellerQueue* w[],int length){
	int count =0;
    //Each time check if the line of index i is empty, add one to the count if not empty.
	for(int i=0;i<length;i++){
		if(!w[i]->isEmpty()){
			count++;
		}
	}
    
    //If all lines are empty, return -1. Otherwise create a array of integers to hold the index of non-empty lines. Add all the indexes to the array and randomly choose one if there is more than 1 non-empty lines.
	if(count==0){
		return -1;
	}
	else
	{
		int a[count];
		count =0;
		for(int i=0; i<length;i++){
			if(!w[i]->isEmpty())
			{
					a[count]=i;
					count++;
			}
		}
		if(count==1)
		{
			return a[0];
		}
		else
		{
			int c = int(rand()%count);
			return a[c];
		}
	}

}


