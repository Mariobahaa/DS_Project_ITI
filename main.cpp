#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#include "System.h"
#include "Customer.h"
using namespace std;

int main()
{
    Customer* c1 = NULL;
    Customer* c2 = new Customer(0,0);
    c1 = c2;
    cout << c1->getArrival();

    /*Customer c1(1,3);
    Customer c2(0,3);
    Customer c3(2,3);
    list<Customer*> inpt;
    inpt.push_back(&c1);
    inpt.push_back(&c2);
    inpt.push_back(&c3);
    inpt.sort( [](Customer* a, Customer* b) {
        return a->getArrival() < b->getArrival();
    });


    queue<Customer*> Q;
    list<Customer*>::iterator it;
    for(it=inpt.begin(); it != inpt.end(); ++it)
    {
        Q.push(*it); //enqueue
    }

    cout<< "Q Size: " << Q.size() << endl;
    while(!Q.empty()){
        cout << Q.front()->Arrival << endl;
        Q.pop();
    }*/
    return 0;
}



///class system --> waiting Queue (STL|Ours), Entry LinkedList<customer> (SORT)
///             --> LinkedList<server>
///class server --> Idle/Working, LinkedList<Customer>, LisnkedList<int> (Timestamp)
///class customer --> LinkedList<Interruptions>, Arrival, Departure, ServiceTime
///LinkedList<event_type>  LinkedList<time> (Event, It's Time stamp)
///


///Global List of Interruptions (Sorted)

/*
    list<Customer>::iterator it;
    for(it=inpt.begin(); it != inpt.end(); ++it)
        cout << it->Arrival << endl;
    */