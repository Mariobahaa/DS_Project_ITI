#ifndef SEVENT_H
#define SEVENT_H

#include "Customer.h"

class SEvent
{
    Customer* ServedCustomer;
    int entryTime;
    public:
        SEvent(){}
        SEvent(Customer* cst, int tm){
            ServedCustomer = cst;
            entryTime = tm;
        }


};

#endif // SEVENT_H
