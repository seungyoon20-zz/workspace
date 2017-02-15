/*============PA4==============ywang20*/
#ifndef EVENT_H_
#define EVENT_H_

#include <string>
#include <iostream>
//#include "Teller.h"
class Teller;

class Event{
public:
    enum Type{
       
        CUSTOMER,
        EDLE,
        SERVICE
    };
    Type type;
    
    Event *next;
    
    
    Event();
    Event(Type _t, float _time);
    Event(Type _t, float _time, Teller *_teller);
    ~Event();
    
    Teller* chooseTeller(Teller* _teller, int size);
    
    void setServiceTime(float f);
    void setWaitTime(float f);
    
    float getServiceTime();
    float getWaitTime();
    
    float getTime();
private:
    float time;             //arrival time of CUSTOMER|| end time of EDLE/SERVICE
    
    float waitTime;
    float serviceTime;      //CUSTOMER
    
    Teller *t;       //EDLE/SERVICE
};

#endif
