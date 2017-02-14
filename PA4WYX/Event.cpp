#include <iostream>
#include "Event.h"
#include "Teller.h"

Event::Event(): type(CUSTOMER), next(0), time(0), waitTime(0), serviceTime(0), t(0){}
Event::Event(Type _t, float _time): type(_t), next(0), time(_time), waitTime(0), serviceTime(0), t(0){}
Event::Event(Type _t, float _time, Teller *_teller): type(_t), next(0), time(_time), waitTime(0), serviceTime(0), t(_teller){}

Event::~Event(){
    if(next){
        delete next;
    }
    t = 0;
}

Teller* Event::chooseTeller(Teller* _teller, int size){
    int k = 0;
    int shortest = 0;
    for(int i = 0; i < size; i++){
        k = (*(_teller+i)).getLineLength() < shortest? i : k;
    }
    return _teller+k;
}

void Event::setServiceTime(float f){
    serviceTime = f;
}
void Event::setWaitTime(float f){
    waitTime = f;
}


float Event::getServiceTime(){
    return serviceTime;
}
float Event::getWaitTime(){
    return waitTime;
}


float Event::getTime(){
    return time;
}

