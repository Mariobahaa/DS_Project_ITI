#ifndef CEVENT_H
#define CEVENT_H

enum custEvent
{
    cserve,cintr, cexit
};
///Typeof Event, Server of Event, Time of Event
class CEvent
{
    custEvent CEventType;
    int CEventTime;
    int serviceDuration;
    int EServId;

public:

    CEvent()
    {
    }


    CEvent(int tm, custEvent evnt,int sid)
    {
        CEventTime = tm;
        CEventType = evnt;
        EServId = sid;

    };

    custEvent getEventType()
    {
        return CEventType;
    }

    int getEventTime()
    {
        return CEventTime;
    }

    int getEServId()
    {
        return EServId;
    }
    int getServiceDuration()
    {
        return serviceDuration;
    }
};
#endif // CEVENT_H
