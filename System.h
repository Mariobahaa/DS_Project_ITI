#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <queue>
#include <list>

#include "Customer.h"

#endif // SYSTEM_

using namespace std;

class System
{
    queue<Customer*> input;
    queue<Customer*> waitingQueue;
    //list<Server> servers;
    int serversNo;
    int custNo;
    int clock;

    public:
    System(list<Customer*>inpt, int serversNum,int custNum){
        serversNo = serversNum;
        custNo = custNum;
        clock = 0;

        GenerateSortedInputQ(inpt);

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

    void Start(){
        while(!input.empty()){
            ///1.Fetch Arriving Customers from Input into Waiting Queue
            if(input.front()->getArrival()==clock)
            {
                ///1.Fetch Arriving Customers from Input into Waiting Queue
                ///2.Check for Interruptions and Execute Interruption Handling
                ///!-- Add Event Data in Customer
                ///3.Fetch Customers into Empty Servers
                ///!-- Save Customer Data in Servers
                ///

            }
            else
            {
                clock++;
            }
        }
    }

    //void enterWaitingQueue()
};

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
