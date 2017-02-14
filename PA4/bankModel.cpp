
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
 */
int timeRange,avgTime,numCus,numTell,cTime;
float avgTimeM;
Event *lastEvent;
int getShortestWaitingLine(tellerQueue* w[],int length);
float getSTD(int **a,int row,int col,float avg);
unsigned int seed = 1234567890;

int main (int argc, char* argv[]){
	eventQueue *head = new eventQueue();
	cTime =0;
	
	if(argc<5) {
		cout << "You have wrong command line input\n";
		exit(-1);
	}
	 numCus = atoi(argv[1]);
	 numTell = atoi(argv[2]);
	 timeRange =atoi(argv[3]);
	 avgTimeM = atof(argv[4]);
    if(argc > 5){
        seed = atoi(argv[5]);
    }
    else{
        seed = time(0);
    }
    
    srand(seed);

	timeRange = timeRange*60;		//Change the Time range from minutes to seconds.
	avgTime =(int)(avgTimeM*60);   	//change avgTime from float minutes to int seconds
	cout <<"Average Service Time:(in seconds)"<< avgTime <<endl << "Time Range:(in seconds)"<<timeRange<<endl;
    tellerQueue *waitingList[numTell]; // Creating
    int TellerData[numTell][2];		// Create an array of integer to record the teller's data for serving and idling. TellerData[][0] for serving time and TellerData[][1] for idle time
    int customerData[numCus][2];
									//Setting up the bank model right now.

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

   for(int i=0;i<numTell;i++){					// Add teller event to the beginning of the
	   waitingList[i]=new tellerQueue();
	   Teller *a = new Teller();
	   a->setExTime(0);
	   a->setNum(i);
	   head->addEvent(a);
	   TellerData[i][0]=0;
	   TellerData[i][1]=0;
   }

   while(!head->isEmpty()&&head->hasCus()){								// running the event queue
	   cTime = head->getExTime();				// Update the current time
	   if(head->isTeller()){

		   int num = head->getNum();			// record the teller number
//		   if(head->isServ()) cout<<"Teller "<<num<<" service ends at "<<cTime<<endl;
//		   if(!(head->isServ())) cout<<"Teller "<<num<<" idle ends at "<<cTime<<endl;
//		   TellerData[num][0] = TellerData[num][0]+head->getServeTime();		// update the teller data.
//		   TellerData[num][1] = TellerData[num][1]+head->getIdleTime();		// update the teller data.

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
//			   cout << "Teller "<<num<<" gets a service at "<<cTime<<endl;
			   head->addEvent(c);
			   head->inServeC();
			   waitingList[num]->dequeue();     // move the waiting list
			   TellerData[num][0] = TellerData[num][0]+serveT;		// update the teller data.
			   customerData[cusNum][0]=customerData[cusNum][0]+serveT;
			   customerData[cusNum][1]=customerData[cusNum][1]+wTime;

		   }
		   else									// for the shortest line of others
		   {

			   int tNum = getShortestWaitingLine(waitingList,numTell);
			   if(waitingList[tNum]->isEmpty()){			//The case for the idle time
				  Teller* t = new Teller();
				  t->setNum(num);
				  t->Action(0,false,cTime);
				  int idleTime = t->getIdleTime();
				  TellerData[num][1] = TellerData[num][1]+idleTime;		// update the teller data.
				  head->addEvent(t);
				  //cout << cTime<<" Idle "<<idleTime<<endl;
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
//		   cout<<"Customer comes at "<<head->isTeller()<<endl;
//		   cout<<"Customer comes at "<<cTime<<endl;
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
   int totalSpentT1 = 0;
   int maxWaitTime =0;
    int avgT1 = 0;
   for(int i=0;i<numTell;i++){
	   cout<< "The Teller "<<i<<" serves "<<TellerData[i][0]<<" seconds and ildes " <<TellerData[i][1]<<endl;
	   totalServeTime+= TellerData[i][0];
	   totalIdleTime+= TellerData[i][1];
   }
   for(int i=0;i<numCus;i++){
	   cout<< "The Customer "<<i<<" has service "<<customerData[i][0]<<" seconds and waits " <<customerData[i][1]<<endl;
	   totalServeTimeC+= customerData[i][0];
	   if(customerData[i][1]>maxWaitTime) maxWaitTime = customerData[i][1];
       totalSpentT1 = totalSpentT1+customerData[i][0]+customerData[i][1];
   }
    
    avgT1 =float(totalSpentT1/head->getServeC());
    
    float std = 0;
    for(int i=0;i<numCus;i++)
    {
        int sum=0;
        for(int j=0;j<2;j++)
        {
            sum = sum+customerData[i][j];
        }
        std= std+float(sum-avgT1)*float(sum-avgT1);
    }
    std=float(std/numCus);
    std = sqrt(std);
    
    cout <<endl<< "Number of customers served "<<head->getServeC()<<endl;
	cout << "Total time required to serve customers: "<<totalServeTimeC<<endl;
	cout <<"Number of tellers : "<<numTell<<endl;
    cout<< "Average time spent by customer is " << avgT1 <<" STD is "<<std<<endl;
	cout<<"Multiple lines."<<endl;
	cout<< "Maximum wait time for a customer: "<<maxWaitTime<<endl;
	cout<<"Total service time : "<<totalServeTime<<"  Total idle time: "<<totalIdleTime<<endl<<endl;


	/**************************************************************************************************
	 * *********************************************************for the common line********************************************************************
	 *********************************************************************************************************/
	head = new eventQueue();
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

	   for(int i=0;i<numTell;i++){					// Add teller event to the beginning of the
		   Teller *a = new Teller();
		   a->setExTime(0);
		   a->setNum(i);
		   head->addEvent(a);
		   TellerData[i][0]=0;
		   TellerData[i][1]=0;
	   }

	   while(!head->isEmpty()&&head->hasCus()){								// running the event queue
		   cTime = head->getExTime();				// Update the current time
		   if(head->isTeller()){

			   int num = head->getNum();			// record the teller number
	//		   if(head->isServ()) cout<<"Teller "<<num<<" service ends at "<<cTime<<endl;
	//		   if(!(head->isServ())) cout<<"Teller "<<num<<" idle ends at "<<cTime<<endl;
	//		   TellerData[num][0] = TellerData[num][0]+head->getServeTime();		// update the teller data.
	//		   TellerData[num][1] = TellerData[num][1]+head->getIdleTime();		// update the teller data.

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
	   for(int i=0;i<numTell;i++){
		   cout<< "The Teller "<<i<<" serves "<<TellerData[i][0]<<" seconds and ildes " <<TellerData[i][1]<<endl;
		   totalServeTime2+= TellerData[i][0];
		   totalIdleTime2+= TellerData[i][1];
	   }
	   for(int i=0;i<numCus;i++){
		   cout<< "The Customer "<<i<<" has service "<<customerData[i][0]<<" seconds and waits " <<customerData[i][1]<<endl;
		   totalServeTimeC2+= customerData[i][0];
		   if(customerData[i][1]>maxWaitTime) maxWaitTime2 = customerData[i][1];
		   totalSpendT2 = totalSpendT2+customerData[i][0]+customerData[i][1];
	   }
    
	   avgT2 =float(totalSpendT2/head->getServeC());
    
        float s = 0;
        for(int i=0;i<numCus;i++)
        {
            int sum=0;
            for(int j=0;j<2;j++)
            {
                sum = sum+customerData[i][j];
            }
            s= s+float(sum-avgT2)*float(sum-avgT2);
        }
        s=float(s/numCus);
        s = sqrt(s);
    
		cout <<endl<< "Number of customers served "<<head->getServeC()<<endl;
		cout << "Total time required to serve customers: "<<totalServeTimeC2<<endl;
		cout <<"Average Time spend by customer: "<< avgT2<< " and STD is "<< s<<endl;
		cout <<"Number of tellers : "<<numTell<<endl;
		cout<<"Common line."<<endl;
		cout<< "Maximum wait time for a customer: "<< maxWaitTime2<< endl;
		cout<<"Total service time : "<<totalServeTime2<<"  Total idle time: "<<totalIdleTime2<<endl<<endl;

//		delete[] commonLine;

}



int getShortestWaitingLine(tellerQueue* w[],int length){	//find the shortest line in the waiting list
	 int l=0;
	int tNum =0;
	for(int i=0;i<length;i++){
		int len=0;
		if(!w[i]->isEmpty()) len =w[i]->getLength();

		if(len<l){
			l =len;
		     tNum =i;
		}
	}
	return tNum;
}




