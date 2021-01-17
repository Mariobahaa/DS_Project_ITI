#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <queue>
#include <list>
#include "Customer.h"
#include <map>
///class server --> Idle/Working, LinkedList<Customer>, LisnkedList<int> (Timestamp)

using namespace std;

class Server
{

    //Cust* ,( event, time), ( event, time)
    bool working;
    //list<SEvent> customerHistory;

    Customer * CurrCustomer ; // Currently Served Customer in this Server
    int ServerID;
public:

    Server()
    {
        working = false;
    }
    Server(int id)
    {
        working = false;
        ServerID = id;
    }
    void setWorking(bool state){
       working=state;
    }
    bool getWorking()
    {
        return working;
    }

    Customer * getCurrCustomer(){
        return CurrCustomer;
    }

    void setCurrCustomer(Customer*cst){
        CurrCustomer = cst;
    }

    int getServerID(){
        return ServerID;
    }
};

#endif // SERVER_H

/*
///overhead Report Customer
Customer inc ->  CEvent
CEvent ptr -> Server <-----
Server ptr -> Customer
Customer inc ->  CEvent


Event Table:
Customer, Server, EventType, time












C2 , 2 , enter , S2

C2 , 4 , exit  , S2
-------
C1 , 10, enter , S2

S1:
C1 , 1 , enter , S1
C1 , 4 , exit  , S1

S2:
C2->id , (2 , enter , S2),( 4 , exit  , S2)
C1 , 10, enter , S2

S3:
C1 , 20, enter , S3



///overhead Report Customer
Customer inc ->  CEvent
CEvent ptr -> Server <-----
Server ptr -> Customer
Customer inc ->  CEvent

///overhead Report Customer
Customer inc ->  CEvent
Server ptr -> SEvent--> Customer
           -> Server
*/

