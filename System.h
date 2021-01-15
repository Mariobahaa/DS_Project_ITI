#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <queue>
#include <list>

#include "Customer.h"
#include "Server.h"

#endif // SYSTEM_

using namespace std;

class System
{
    queue<Customer*> input;
    queue<Customer*> waitingQueue;
    queue<pair<int,Server*>> Interruptions; //time,Interrupted Server
    list<Server*> Servers;

    int serversNo;
    int custNo;
    int clock;

    public:
    System(list<Customer*>inpt, list<pair<int,Server*>> intr, int serversNum,int custNum){
        serversNo = serversNum;
        custNo = custNum;
        clock = 0;

        GenerateSortedInputQ(inpt);
        GenerateServers();

    }

    void GenerateServers(){
        for(int i=0;i<serversNo;i++)
        {
            Servers.push_back(new Server(i+1));
        }
    }

    void GenerateSortedInputQ(list<Customer*> inpt)
    {
        inpt.sort( [](Customer* a, Customer* b) {
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
        inpt.sort( [](pair<int,Server*> a, pair<int,Server*>  b) {
        return a.first < b.first;
        });


        list<pair<int,Server*>>::iterator it;
        for(it=intr.begin(); it != intr.end(); ++it)
        {
            Interruptions.push(*it);
        }
    }

    void Start(){

        while(!input.empty() ){
            ///1.Fetch All Arriving Customers from Input into Waiting Queue

            while(input.front()->getArrival()==clock && !input.empty())
            {
                waitingQueue.push(input.front());
                input.pop();
            }
            ///2.Check for Interruptions and Execute Interruption Handling
            ///!-- Add Event Data in Customer

            //clock++
        }
    }
    //void enterWaitingQueue()
};

                ///1.Fetch Arriving Customers from Input into Waiting Queue
                ///2.Check for Interruptions and Execute Interruption Handling
                ///!-- Add Event Data in Customer
                ///3.Fetch Customers into Empty Servers
                ///!-- Save Customer Data in Servers
                ///

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

//Interruptions Per Server
