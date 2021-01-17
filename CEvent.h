#ifndef CEVENT_H
#define CEVENT_H
//#include "Server.h"

enum custEvent{
  cserve ,cintr, cexit
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
    int serviceDuration;
    //Server* CServer;
    public:

        CEvent(){
        }

        //CEvent(int tm, custEvent evnt,Server* srv){
        CEvent(int tm, custEvent evnt){
            CEventTime = tm;
            CEventType = evnt;
            //CServer = srv;
        };

        custEvent getEventType(){
            return CEventType;
        }

        int getEventTime(){
            return CEventTime;
        }
int getServiceDuration()
{
    ;
}
};
#endif // CEVENT_H
