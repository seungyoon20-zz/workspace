==========PA4==========ywang20==============mliu2==============

How to Run it
-To compile this program, run “make all” in the command line.
-Then run “./qSim 50 4 60 2.3” to start the simulation of 50 customers, 4 tellers, 60-minute entire time and 2.3-minute average service time without a seed. 
-Or run “./qSim 50 4 60 2.3 1234567890” to give the program a seed of “1234567890”.

How the program works:
bankModel.cpp:
 int main(int argc,char* argv[]):
	-The bankModel has the main function of the program. The main function reads the command-line arguments first: if there are less than 5 arguments, print the problem in the command line and exit; if there are 5 arguments, store argv[1]~argv[4] as number of customers, number of tellers, the simulation time, and average service time for each customer; if there are more than 5 arguments given, initiate the random number generator with argv[5] as the seed.
	-Run the first simulation with every teller has a separate waiting list, then run the second simulation with a common waiting list.
	-Initiate a waiting list for each teller first. Then create 2 2-dimensional arrays of integers TellerData[][] and customerData[][] to store the service time and idle time of each teller and waiting time and overall time of each customer. Start the simulation with a current time of 0sec.
	-For each customer, create a new customer. Then set the index of the customer(the index indicates the position of the customer in the customerData), take action on each customer, add the customer to the eventQueue. And set the waitTime and overall time to 0 in the customerData.
	-Fora each teller, initiate one tellerQueue and create a new teller object, set the execution time to current time 0, take an action, and give each teller an index number and set the service time and idle time to 0. Add the teller to the 
	- Loop through the eventQueue until there is no customer in the eventQueue. Each time the loop continues, firstly set the current time to the ExTime of the head of the eventQueue. 
	-If the head of the eventQueue points to a teller event, check the waiting list of the teller. If there is at least one customer waiting in line, teller takes action: set the serviceTime to a random generated time, set the ExTime to the end of the service and add the teller to the eventQueue again. Modify the total service time of this teller in the tellerData array. Then the customer takes action, set the customer on service, store the waiting time and add the customer to the eventQueue again. If there is no customer in the waiting list of the teller’s personal waiting list, call the int randomSelectLine(tellerQueue* w[],int length) function. If the integer returned doesn’t equal to -1,  grab the first customer from the given index waiting list.
	-If the integer is -1, the program checks if there is customer not yet arriving. If the simulation still need to continue, the teller takes action of idle, else just wait the simulation stop: set the service status to false, modify the idle time and total idle time, and add the teller to the eventQueue again. If there is at least one other teller has customers in waiting least, randomly choosing a line and serve the first customer in the line.
	-Else if the head of the eventQueue is a customer, and the customer’s service status is false(which means the customer just arrives), the customer choose the shortest waiting list and store the current time as the start point of waiting time. Then add the customer to the waiting list.
	-Each time finishing doing the head of the eventQueue, dequeue the head and make the second event head.
	-The first simulation ends and prints all statistics in the commandLine.

	-The second simulation starts with a new common tellerQueue created and all necessary objects(ex. eventQueue, TellerData, customerData) reset. If using seed, the random number generator also need to be reset to make sure that the numbers generated are same as in the first simulation.
	-Loop through the eventQueue until there is no more customer in the eventQueue.
	-When the head of the eventQueue points to a teller, check the common waiting list. If there is at least one customer waiting in line, teller takes action: set the serviceTime to a random generated time, set the ExTime to the end of the service and add the teller to the eventQueue again. Modify the total service time of this teller in the tellerData array. Then the customer takes action, set the customer on service, store the waiting time and add the customer to the eventQueue again. If there is no customer in the waiting list of the teller’s personal waiting list, check all the tellers and store the indexes of tellers who has at least one customer in an array of integer. 
	-If there is no customer waiting in the common waiting line, the program check for the teller if there will be customer arriving afterwards, if yes, the teller takes action of idle: set the service status to false, modify the idle time and total idle time, and add the teller to the eventQueue again.
	-Each time finish checking the head of the common waiting line, dequeue the head and make the second event head.
	-Finish the second simulation by calculating and printing all statistics.

int getShortestWaitingLine(tellerQueue* w[],int length):
	-Loop through the index of tellers, cach time check the line length of the teller of index i, if the length of line i is shorter than the previous shortest line, set i as the shortest line index. Loop until touch the bound. Always get the index of the first one if there are several shortest lines.Then check how many shortest lines are in the entire bank, if the line of index i has a same length as the shortest line, add one to the count. If there is only one shortest line, return its idex, otherwise create a array of integer and of size count to hold all the indexes of the shortest lines. Each time check if the line is of same length with the shortest line, if so, add the index to the array. Randomly choose a index in the array and return the index.

int randomSelectLine(tellerQueue* w[],int length):
	-Check all the tellerQueues in the array. Each time check if the line of index i is empty, add one to the count if not empty.  Otherwise create a array of integers to hold the index of non-empty lines. Add all the indexes to the array and randomly choose one if there is more than 1 non-empty lines.

float getSTD(int a[][2],int row,float avg):
	-calculate the standard deviation of numbers in a 2 dimensional array.
	-Used to calculate the STD of the average time spend of all customers.
=========================================================================
Event:
	-Abstract class with 2 derived class of Customer and Teller.
	-Each event has a pointer to its next event and a pointer to the previous event, and a integer to store the execution time.
	-Event class has a only default constructor initiate exTime as 0, and prevEvent &nextEvent as null. The destructor deletes both the prevEvent and the nextEvent.
	-void setNextEvent(Event *nextEvent)& void setPrevEvent(Event *PrevEvent): set the prevEvent or nextEvent to the given Event pointer.
	-Event* getNextEvent()&Event* getPrevEvent(): return the pointer to nextEvent or prevEvent.
	-void addEvent(Event *e): takes a Event pointer and add the event to this event. If the exTime of the argument is before the exTime of this event, set the given event as prevEvent of this event. If the event happens after this event, set it as the next event of this event if this event doesn’t have a nextEvent, else add the argument event pointer to the next event of this event.
	-void setExTime(int time): set the ExTime or return the ExTime.
	-Event::dequeue(): remove the first event in the eventQueue that this event exists, return the second event in this eventQueue.
	-int getLength(): return the number of events that happen after this event.
	-void Action(int timeRange,bool isServ,int cTime): this function is different if the event is a teller or is a customer.
========================================================================
Customer:
	-Customer class is a derived class of Event class.
	-Customer class has extra member variables of sTime(the time customer start to wait in the waitingLine), ctime and cusNumber(index in the customerData).
	-void Customer::Action(int time,bool isServ,int cTime): first set the given current time as the current time of the customer, modify the service status of the customer. If the given inServ is false, which means this action is to initialize the customer, give the customer a randomly generated arrival time. If the given ifServ is false, which means the customer just get out of the waiting list and is getting service from the teller, set its service time.
	-bool Customer::isTeller(): Always return false.
	-bool Customer::isServ(): Return true if customer is in service, otherwise false.
	- void Customer::setCTime(int t): set the currentTime of the customer.
	- int Customer::getCTime(): return the current time of the customer.
	-void Customer::setNum(int n): set the index of the customer.
	- int Customer::getNum():return the index of the customer.
========================================================================
Teller:
	-Teller is a derived class of Event.
	-Teller has its own member variables of idleTime, serveTime, tellerNum, and a bool value isService to store its status.
	-void Teller::setIdleTime(int cTime): randomly generate a idle time from  1- 150 seconds and set the idleTime and execution time of the teller.
	-void Teller::setServeTime(int avgTime,int cTime) : generate a service time in range of 1 to 2*avgTime and set the exTime to be cTime plus serveTime.
	-void Teller::Action(int avgTime,bool isServ,int cTime): modify the isService first. If isService is true, the teller need to start serve customer and setServeTime, if isService is false means the teller start to idle, so call setIdleTime().
	-bool Teller::isTeller(): Always return true.
	-Other functions just help get or modify the member variables and statistics.
=======================================================================
eventQueue:
	-eventQueue has a private variable of serveC recording how many customers has been serve in the simulation. And a public Event* indicates the head of the eventQueue.
	-constructor& destructor: The constructor initiate the head to null and serveC to 0. The destructor deletes the head event.
	-void addEvent(Event* e): Add the arguments Event* to the head and set the head again.
	-bool isEmpty(): Check if the head points to a event, if yes return true, else false.
	-Event* getHead(): return the head of the eventQueue.
	-bool hasCus(): Check from the head, if the iterator event is a customer, return true, else check the next until the tail.
	-bool isTeller(): return true if the first event is a teller. Otherwise false.
	-bool isServ(): return true if the first event is in service .
	-int getExTime(): return the execution time of the head.
	-void inServeC(): add the number of served customers.
	-int getServeC(): return the number of customer served.

=======================================================================
tellerQueue:
	-Waiting list of the teller. The member waitingList points to the first customer in the waiting list. The tellerNum is the index of the teller that use the teller Num(used in the first simulation).
	-constructor& destructor: The constructor initiate the waitingList to null and tellerNum 0. The destructor deletes the waitingList pointer.
	-Event* getList(): return the waitingList pointer.
	-getNum()&setNum(0: get or modify the index of the teller that uses this waitingList.
	-void addEvent(Event* e): add a customer event to this tellerQueue by add the event to the first event in the tellerQueue.
	-bool isEmpty(): if the first customer is null, return true, false otherwise.
	-void dequeue(): call dequeue function to the first customer waiting in this teller queue: remove the first customer in the tellerQueue and make the next points to the waitingList pointer.
	-int getExTime(): get the execution time of the first customer in waiting list.
	-void setHead(Event* e): set the first customer points to the given Event*.
	-int getLength(): return 0 if the first customer points to null, else count from the waitingList and return the length.

======================================================================
Analysis with the 2 common line mode and multi-line mode simulations:
 
Tow modes are similar when the number of customers is small. This is because when there is a small number of customer, customers usually do not need to wait in line to get service. While as the number of customer increases, the second simulation shows that common-line mode is much better than the multi-line mode that the average time each customer stay in the bank is smaller and the maximum waiting time is also smaller. The tellers also spend less time idle.
In my perspective, this is because always choosing the shortest line may not make the customer get service most fast. Since the service time of customers before is totally random generated, the customer may waste time if the previous customers took too long.
While in the common-line simulation, customer will never waste time on this point since the customer doesn’t have to choose a line when arriving at the bank.





