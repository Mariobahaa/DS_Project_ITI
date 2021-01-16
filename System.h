#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <iterator>
#include "Customer.h"
#include "Server.h"

#endif // SYSTEM

using namespace std;

///for testing the interruption list
int Print(const pair<int, Server*>  &intr)
{
    cout <<"\ninterruption at: "<< intr.first;
}






class System
{
    queue<Customer*> input;
    queue<Customer*> waitingQueue;
    queue<pair<int,Server*>> Interruptions; //time,Interrupted Server
    list<Server*> Servers;

    int serversNo;
    int custNo;
    int clock;

    void GenerateServers()
    {
        for(int i=0; i<serversNo; i++)
        {
            Servers.push_back(new Server(i+1));
        }
    }

    void GenerateSortedInputQ(list<Customer*> inpt)
    {
        inpt.sort( [](Customer* a, Customer* b)
        {
            return a->getArrival() < b->getArrival();
        });


        list<Customer*>::iterator it;
        for(it=inpt.begin(); it != inpt.end(); ++it)
        {
            input.push(*it);
        }
    }


    void GenerateSortedIntrptQ(list<pair<int,Server*>> intr)
    {
        intr.sort( [](pair<int,Server*> a, pair<int,Server*>  b)
        {
            return a.first < b.first;
        });


        /*list<pair<int, Server*> >::iterator it2;
        for_each(intr.begin(), intr.end(), Print);///USES ALGORITHM LIBRARY
        */

        list<pair<int,Server*>>::iterator it;
        for(it=intr.begin(); it != intr.end(); ++it)
        {
            Interruptions.push(*it);
        }
    }



    ///1.Fetch All Arriving Customers from Input into Waiting Queue
    void fetchArriving()
    {
        bool exit = false;
        while(!input.empty() && !exit)
        {
            if(input.front()->getArrival()==clock)
            {
                waitingQueue.push(input.front());
                input.pop();
            }
            else {
                exit = true;
            }
        }
    }


    ///2.Check for Interruptions and Execute Interruption Handling
    void checkIntrpt()
    {

        Customer * currCustomer;
        if(!Interruptions.empty())
            while(!Interruptions.empty()&&Interruptions.front().first==clock)
            {
                if(Interruptions.front().second->getWorking()==true)
                {
                    currCustomer = Interruptions.front().second->getCurrCustomer();
                    waitingQueue.push(currCustomer);
                    Interruptions.front().second->setWorking(false);

                    ///!-- Add Event Data in Customer
                    CEvent custEvent(clock,cexit);
                    Interruptions.front().
                    second->addEvent(currCustomer,custEvent);
                }
                Interruptions.pop();
            }
    }

    ///3.Fetch Customers into Empty Servers
    void fetchToServers()
    {
        Server* server;
        if(!waitingQueue.empty()&& !Servers.empty())
        {
            list<Server*>::iterator srvit;
            for(srvit=Servers.begin(); srvit!=Servers.end(); srvit++)
            {
                server = *srvit;
                if(!server->getWorking())
                {
                    server->setCurrCustomer(waitingQueue.front());
                    waitingQueue.pop();
                    server->setWorking(true);

                    ///!-- Add Event Data in Customer
                    CEvent custEvent(clock,cserve);
                    server->addEvent(server->getCurrCustomer(),custEvent);
                }
            }
        }
    }

    ///Remaining Time-- and Remove Finished Clients  & Clock++
    void advance()
    {
        //clock++
        list<Server*>::iterator itt;
        for(itt=Servers.begin(); itt!=Servers.end(); itt++)
        {
            Server*server = *itt;
            if(server->getWorking())
            {
                server->getCurrCustomer()->decrementRT();
                if (server->getCurrCustomer()->getRemainingTime()==0)
                {
                    server->setWorking(false);
                    CEvent custEvent(clock,cexit);
                    server->addEvent(server->getCurrCustomer(),custEvent);
                }

            }
        }
        clock++;
    }


public:
    System(list<Customer*>inpt, list<Server*> servers, list<pair<int,Server*>> intr, int serversNum,int custNum)
    {
        serversNo = serversNum;
        custNo = custNum;
        clock = 0;
        Servers= servers;

        GenerateSortedInputQ(inpt);
        //GenerateServers();
        GenerateSortedIntrptQ(intr);

    }
    /*
            System(list<pair<int,Server*>> intrr)///3amalt constructor tany 3shan agrb 3leh el interruptions bs
            {

            GenerateSortedIntrptQ(intrr);

            }*/

    bool serversState(){
        list<Server*>::iterator it;
        Server*S;
        for(it=Servers.begin();it!=Servers.end();it++)
        {
            S = *it;
            if(S->getWorking() == true){
                return true;
            }
        }
    }

    void Start()
    {
        while((!input.empty() && !waitingQueue.empty() )|| serversState() )
        {
            fetchArriving();
            checkIntrpt();
            fetchToServers();
            advance();
        }
    }
    //void enterWaitingQueue()
};

///1.Fetch Arriving Customers from Input into Waiting Queue
///2.Check for Interruptions and Execute Interruption Handling
///!-- Add Event Data in Customer
///3.Fetch Customers into Empty Servers
///!-- Save Customer Data in Servers
///Remaining Time-- and Remove Finished Clients  & Clock++

/*
void insertionSort()
    {
        Node<T> *current = head;
        Node<T> *selected=NULL;
        while (current != NULL)
        {
            selected->Next = current->Next;
            sortedInsert(selected, current);
            current = current->Next;
        }
head=selected;
    }
*/

/*
              list<pair<int,Server*>>::iterator it3;
            while(Interruptions.front().first==clock&&Interruptions.front().second->getWorking()==true&&!Interruptions.empty())
            { ///STILL INCOMPLETE
                waitingQueue.push(Interruptions.front().second->custHistory.begin()->first);
                Interruptions.front().second->setWorking(false);
                  CEvent ce(clock,cexit);
//
            }
*/

//Interruptions Per Server
