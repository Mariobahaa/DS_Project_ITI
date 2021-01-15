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

        inpt.sort( [](Customer* a, Customer* b) {
        return a->Arrival < b->Arrival;
        });


    list<Customer*>::iterator it;
    for(it=inpt.begin(); it != inpt.end(); ++it)
    {
        input.push(*it);
    }



    }

    void StartSystem(){
        while(!input.empty()){
            if(input.front()->Arrival==clock)
            {
                ///enter waiting queue

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
