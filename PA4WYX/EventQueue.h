#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

//#include "Event.h"
class Event;

class EventQueue{
public:
    EventQueue();
    ~EventQueue();
    
    void insertEvent(Event* e);
    Event* dequeueFirstEvent();
    
    int getSize();
private:
    int size;
    Event *head;
    
};
#endif
