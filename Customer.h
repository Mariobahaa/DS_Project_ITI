#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <queue>
#include <list>
#include "CEvent.h"


using namespace std;

///Customer Events
///entry: enter waiting queue
///interrupted: interrupted at service
///exit:


class Customer
{
    list<int> Interruptions;
    int Departure, ServiceTime,Arrival,RemainingTime;
    CEvent c;
    public:

    getArrival(){
        return Arrival;
    }
    //Customer(list<int>Intr, int arrival, int departure, int st){
    Customer(int arrival, int st){

        //Interruptions = Intr;
        Arrival = arrival;
        ServiceTime= st;
        RemainingTime = st;
        Departure = -1;

    }

};

#endif // CUSTOMER_H
