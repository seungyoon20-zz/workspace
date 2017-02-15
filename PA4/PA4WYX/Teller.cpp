#include <iostream>
#include <cstdlib>
#include "Teller.h"
#include "EventQueue.h"
#include "Event.h"

Teller::Teller(): averageServiceTime(0), prevTime(0), totalEdleTime(0), totalServiceTime(0),ifWorking(false), totalCus(0){
    *customers = EventQueue();
}
Teller::Teller(float average): averageServiceTime(average), prevTime(0), totalEdleTime(0), totalServiceTime(0), ifWorking(false), totalCus(0){
    //*customers = NULL;
    *customers = EventQueue();
}
Teller::~Teller(void){
    delete customers;
    return;
}

void Teller::enqueueCustomer(Event* customerEvent){
    (*customers).insertEvent(customerEvent);
}

float Teller::getFirstCustomer(){
    Event* e = (*customers).dequeueFirstEvent();
    float serviceTime = 2*averageServiceTime*rand()/float(RAND_MAX);
    (*e).setServiceTime(serviceTime);
    (*e).setWaitTime(prevTime - (*e).getTime());
//    Event newEvent(Event::SERVICE, 2*averageServiceTime*rand()/float(RAND_MAX));
//    EQ.insertEvent(newEvent);
//    prevTime += serviceTime;
    totalCus += 1;
    return serviceTime;
}

void Teller::getCusomterFromOtherTeller(Teller* t, int size){
////    int i = size*rand()/int(RAND_MAX);
////    if(*(t+i).getLineLength)
//    bool
//    for(int i = 0; i < size; i++){/Users/wangyixue/Documents/2017TermC/workspace/PA4/Teller.h
//        if
//    }
    return;
}
void Teller::removeFirstCustomer(){
    (*customers).dequeueFirstEvent();
}



int Teller::getLineLength(){
//    if(customers){
        return customers->getSize();
//    }
//    else {
//        return 0;
//    }
    return 0;
}

float Teller::getPrevTime(){
    return prevTime;
}
void Teller::setPrevTime(float newT){
    prevTime = newT;
    
}



