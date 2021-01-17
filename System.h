#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <queue>
#include <list>
#include "Customer.h"
#include "Server.h"

#endif // SYSTEM

using namespace std;

class System
{
    queue<Customer*> input;
    queue<Customer*> waitingQueue;
    queue<pair<int,Server*>> Interruptions; //time,Interrupted Server
    list<Server*> Servers;
    list<Customer*>customersCpy;

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

        customersCpy = inpt;

        list<Customer*>::iterator it;
        for(it=inpt.begin(); it != inpt.end(); ++it)
        {
            input.push(*it);
            cout << (*it)->getCustId() << endl;
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
                cout << input.front()->getCustId() << "C entering Queue" << endl;
                input.pop();
            }
            else
            {
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
                    CEvent custEvent(clock,cintr,Interruptions.front().second->getServerID());
                    currCustomer->addEvent(custEvent);
                }
                Interruptions.pop();
                cout << "Popped Interruption" << endl;
            }
    }

    ///3.Fetch Customers into Empty Servers
    void fetchToServers()
    {
        Server* server;
        if(!waitingQueue.empty()&& !Servers.empty()) //skips
        {
            list<Server*>::iterator srvit;
            for(srvit=Servers.begin(); srvit!=Servers.end(); ++srvit)
            {
                server = *srvit;
                if(!server->getWorking() && !waitingQueue.empty()) //<<<<
                {
                    server->setCurrCustomer(waitingQueue.front());
//                    cout << "Serving C" << waitingQueue.front()->getCustId() <<
//                         " in Server " << server->ServerID<<endl;
                    waitingQueue.pop();
                    server->setWorking(true);


                    ///!-- Add Event Data in Customer
                    CEvent custEvent(clock,cserve,server->getServerID());
                   server->getCurrCustomer()->addEvent(custEvent);

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
                    cout << "C" << server->getCurrCustomer()->getCustId() <<"Exiting" << endl;
                    CEvent custEvent(clock+1,cexit,server->getServerID());
                    server->getCurrCustomer()->setDeparture(clock+1);
                    server->getCurrCustomer()->addEvent(custEvent);


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
        customersCpy=inpt;
        GenerateSortedInputQ(inpt);
        //GenerateServers();
        GenerateSortedIntrptQ(intr);

    }
    /*
            System(list<pair<int,Server*>> intrr)///3amalt constructor tany 3shan agrb 3leh el interruptions bs
            {
            GenerateSortedIntrptQ(intrr);
            }*/

    bool serversState()
    {
        list<Server*>::iterator it;
        Server*S;
        for(it=Servers.begin(); it!=Servers.end(); it++)
        {
            S = *it;
            if(S->getWorking() == true)
            {
                return true;
            }
        }
    }

    void Report()
            {
                system("CLS");
                if(serversNo<=0 || custNo <= 0){cout<< "Unable to start the system" << endl; return;}
                cout<< "\n\t\t\t\t\t\t    System Report"<< endl << endl <<endl;
                list<Customer*>::iterator itr;
                list<CEvent>::iterator it;
                Customer* cstmr;
              // cout<<"no service to process";
                for (itr = customersCpy.begin(); itr != customersCpy.end(); ++itr)
                {
                    cstmr=*itr;
                    //cout<<"New Customer" << endl;
                    cout << "\n\t\t\t\tCustomer\tArrivalTime\tTotalTimeSpent\t  TotalWaitingTime\n";
                    cout << "\t\t\t\t   C" << cstmr->getCustId();
                    cout<<"\t\t    "<<cstmr->getArrival();
                    cout<<"\t\t    "<<cstmr->getTimeSpent();
                    cout<<"\t\t\t"<<cstmr->getTimeSpent()-cstmr->getServiceTime();
                    cout<<"\n\n\t\t"<<"\t\tEvent\t\t   Time\t\tServiceDuration\t     Server\n\n";
                    list<CEvent> cHistory = cstmr->getcustHistory();
                    for(it= cHistory.begin(); it != cHistory.end(); ++it)
                    {
                        /*int serveStart;
                        serveStart=it->getEventTime();*/

                        //cout << "New Event" << endl;
                        if(it->getEventType()==cserve)
                        {
                            cout   << "\t\t\t\t" <<"ServeStarted"<<"\t    " <<it->getEventTime();
                            cout<<"\t\t    "  << "-";
                           cout<<"\t\t\tS"  << it->getEServId()<< endl;

                        }
                        else if(it->getEventType()==cintr)
                        {
                            cout   << "\t\t\t\t" <<"Interruption"<<"\t    " << it->getEventTime();
                            cout<<"\t\t    "  << it->getEventTime(); //-serveStart;
                            cout<<"\t\t\tS"  << it->getEServId()<< endl;
                        }
                        else if(it->getEventType()==cexit)
                        {
                            cout   << "\t\t\t\t" <<"Exited"<<"\t\t    "  << it->getEventTime();
                            cout<<"\t\t    "  << it->getEventTime();//-serveStart;
                            cout<<"\t\t\tS"  << it->getEServId()<< endl;

                        }

                    }
                    //cout << "Customer Events Done";
                    cout<<"\n\n\n\n";
                }

            }

    void Start()
    {
        if(serversNo<=0 || custNo <= 0){cout<< "System Unable to Operate" << endl; return;}
        while(!input.empty() || !waitingQueue.empty() || serversState() )
        {
            fetchArriving();
            checkIntrpt();
            fetchToServers();
            advance();
            //Report();


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



///Departure
//done:
//customer--arrival time--interruption time----spent time--comeback time---- spent time--total spent time -- departure
/*not yet:
server number
 -- comeback server
*/

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

///Customer C1 -> S1 , S2, S3x
///S1 -> custHistory [C1]
