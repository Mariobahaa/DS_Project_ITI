#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <queue>
#include <list>
#include "CEvent.h"


using namespace std;

class Customer
{

    int Departure, ServiceTime,Arrival,RemainingTime, CustId,TimeSpent;

    list<CEvent> custHistory;

public:

    Customer(int arrival, int st, int id)
    {

        CustId = id;
        Arrival = arrival;
        ServiceTime= st;
        RemainingTime = st;
        Departure = -1;

    }

    Customer() {;}

    int getArrival()
    {
        return Arrival;
    }

    int getCustId()
    {
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

    void addEvent(CEvent ce)
    {
        custHistory.push_back(ce);
    }

    int getServiceTime()
    {
        return ServiceTime;
    }

    list<CEvent> getcustHistory()
    {
        return custHistory;
    }

};

#endif // CUSTOMER_H
