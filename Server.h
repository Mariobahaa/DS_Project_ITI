#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <queue>
#include <list>
#include "Customer.h"

using namespace std;

class Server
{


    bool working;

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
    void setWorking(bool state)
    {
        working=state;
    }
    bool getWorking()
    {
        return working;
    }

    Customer * getCurrCustomer()
    {
        return CurrCustomer;
    }

    void setCurrCustomer(Customer*cst)
    {
        CurrCustomer = cst;
    }

    int getServerID()
    {
        return ServerID;
    }
};

#endif // SERVER_H
