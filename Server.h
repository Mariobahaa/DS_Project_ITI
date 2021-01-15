#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <list>
#include <queue>
#include "Customer.h"
#include "CEvent.h"
#include "SEvent.h"

///class server --> Idle/Working, LinkedList<Customer>, LisnkedList<int> (Timestamp)

using namespace std;

class Server
{

    bool working;
    list<SEvent> customerHistory;
    public:
        Server(){
            working = false;
        }


};

#endif // SERVER_H
