#ifndef CEVENT_H
#define CEVENT_H
#include "Customer.h"
enum custEvent{
    entry, interrupted , cexit
};

class CEvent
{
    custEvent CEventType;
    int CEventTime;
    public:

        CEvent(){
        }
        CEvent(int tm, custEvent evnt= interrupted){
            CEventTime = tm;
            CEventType = evnt;
        };
};
#endif // CEVENT_H
