#include "EventQueue.h"
#include "Event.h"
#include <iostream>

EventQueue::EventQueue(){
    size = 0;
    head = 0;
}
EventQueue::~EventQueue(void){
    Event *p = head;
    
    while (!p) {
        Event *q = p -> next;
        delete p;
        p = q;
    }
    return;
}

void EventQueue::insertEvent(Event* e){
    Event* event = e;
    if (!head) {
        head = event;
    }
    
    else if (event->getTime() < head->getTime()) {
        event -> next = head;
        head = event;
    }
    
    else {
        Event *q = head;
        while ((q -> next) && ((q -> next)->getTime() < event->getTime())){
            q = q -> next;
        }
        event -> next = q -> next;
        q -> next = event;
    }
    
    size+=1;
    return;
}
Event* EventQueue::dequeueFirstEvent(){
    Event *q = head;
    head  = q -> next;
    size-= 1;
    return q;
}

int EventQueue::getSize(){
    return size;
}





