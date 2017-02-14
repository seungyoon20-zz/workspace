#ifndef TELLER_H_
#define TELLER_H_

//#include "EventQueue.h"
//#include "Event.h"
class EventQueue;
class Event;

class Teller{
public:
    Teller();
    Teller(float average);
    ~Teller();
    
    void enqueueCustomer(Event* customerEvent);
    float getFirstCustomer();
    void getCusomterFromOtherTeller(Teller* t, int size);
    void removeFirstCustomer();
//    void addEdle(EventQueue e);
    
    int getLineLength();
    float getPrevTime();
    void setPrevTime(float newT);
private:
    float averageServiceTime;
    EventQueue* customers;
    
    float prevTime;
    float totalEdleTime;
    float totalServiceTime;
    bool ifWorking;
    int totalCus;
};

#endif
