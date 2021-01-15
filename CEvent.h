#ifndef CEVENT_H
#define CEVENT_H
#include "Customer.h"
#include "Server.h"

enum custEvent{
  cserve , cexit
};
///Typeof Event, Server of Event, Time of Event
/*
cserve, ServerS1, time1
cexit , ServerS1, time2 // interruption
cserve, ServerS1, time1 */

class CEvent
{
    custEvent CEventType;
    int CEventTime;
    Server* CServer;
    public:

        CEvent(){
        }
        CEvent(int tm, custEvent evnt,Server* srv){
            CEventTime = tm;
            CEventType = evnt;
            CServer = srv;
        };
};
#endif // CEVENT_H
