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
    ///list<int> Interruptions; -----> Global
    int Departure, ServiceTime,Arrival,RemainingTime, CustId,TimeSpent;

    list<CEvent> custHistory;
    //list<CEvent> CustEvents;
    public:

    //Customer(list<int>Intr, int arrival, int departure, int st){
    Customer(int arrival, int st, int id){

        //Interruptions = Intr;
        CustId = id;
        Arrival = arrival;
        ServiceTime= st;
        RemainingTime = st;
        Departure = -1;

    }

    Customer(){;}
    ///Report()

    int getArrival(){
        return Arrival;
    }

    int getCustId(){
        return CustId;
    }

    int getRemainingTime()
    {
        return RemainingTime;
    }

    void decrementRT()
    {
        RemainingTime--;
    }

    void setDeparture(int Dep)
    {
        Departure=Dep;
    }
 int getTimeSpent()
    {
        return Departure-Arrival;
    }

    void addEvent(CEvent ce){
        custHistory.push_back(ce);
    }

    list<CEvent> getcustHistory()
    {
        return custHistory;
    }

};

#endif // CUSTOMER_H
