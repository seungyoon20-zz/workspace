/*============PA4==============ywang20*/


#include <iostream>
#include <cstdlib>
#include "EventQueue.h"
#include "Teller.h"
#include "Event.h"
//#include <ofstream>
//class Teller


int main(int argc, char* argv[]){
    using std::cout;
    using std::endl;
    using std::srand;
    
    int numOfCus;
    int numOfTeller;
    float simulationTime;
    float servTime;
    //float seed;
    
    //ofstream output;
    
    if(argc < 5){
        cout << "Need at least 5 arguments!!!" <<endl;
        exit(1);
    }
    
    numOfCus = atoi(argv[1]);
    numOfTeller = atoi(argv[2]);
    simulationTime = atof(argv[3]);
    servTime = atof(argv[4]);
    
    if(argc > 5){
        srand(atof(argv[5]));
    }
    else{
        srand(time(0));
    }
    
    EventQueue* EQ = new EventQueue();
    
    Teller* tellers = new Teller[numOfTeller];
    Event* customerList = new Event[numOfCus];
    
    for(int i = 0; i < numOfCus; i++){
        customerList[i] = Event(Event::CUSTOMER, simulationTime * rand()/float(RAND_MAX));
        EQ -> insertEvent(customerList+i);
    }
    for(int i = 0; i < numOfTeller; i++){
        *(tellers+i) = Teller(servTime);
        //tellers[i].enqueueCustomer(customerList);
        //cout << tellers[i].getLineLength()<< endl;
    }
    //cout << EQ->getSize();

//    Event* iterator;
//    //Teller* currentTeller;
//    while(EQ.getSize() > 0){
//        for(int i = 0; i < numOfTeller; i++){
//            if(tellers[i].getLineLength() > 0){
//                float serviceTime = (teller[i]).getFirstCustomer(EQ);
//                EQ.insertEvent(Event(Event::SERVICE, serviceTime));
//                
//            }
//            else{
//                void e = getCustomerFromOtherTeller(tellers, numOfTeller);
//                if(e){
//                    e = (teller[i]).getFirstCustomer(EQ);
//                }
//                else{
//                    teller.addEddle(EQ);
//                }
//            }
//        }
//        iterator = EQ.dequeueFirstEvent();
//        currentTeller = (*iterator).chooseTeller(tellers, numOfTeller);
//    }
    return 0;
}
