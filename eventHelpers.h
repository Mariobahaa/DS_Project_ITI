#ifndef EVENTHELPERS_H
#define EVENTHELPERS_H

enum custEvent{
    entry, interrupted ,exit
};

class eventHelpers
{
    public:
        eventHelpers();
};


class CEvent
{
    custEvent CEventType;
    int CEventTime;
    public:
        CEvent(int tm, custEvent evnt= custEvent.interrupted){
            CEventTime = tm;
            CEventType = evnt;
        };
};
#endif // EVENTHELPERS_H
