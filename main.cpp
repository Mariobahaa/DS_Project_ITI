#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#include <algorithm>
#include "System.h"
#include "Customer.h"
using namespace std;

int main()
{
    Customer c1(1,3);
    Customer c2(0,3);
    Customer c3(2,3);
    list<Customer> inpt;
    inpt.push_back(c1);
    inpt.push_back(c2);
    inpt.push_back(c3);
    inpt.sort( [](Customer a, Customer b) {
        return a.Arrival < b.Arrival;
    });

    queue<Customer> q;
    q.push(c1);
    q.push(c2);
    q.push(c3);

    list<Customer>::iterator it;
    //xxx q.sort([](Customer * lhs, Customer * rhs) {return lhs->Arrival < rhs->Arrival;});
    /*
    list<Customer>::iterator it;
    for(it=inpt.begin(); it != inpt.end(); ++it)
        cout << it->Arrival << endl;
    */
    for(int i=0;i<q.size();i++){
        cout << q.front().Arrival << endl;
        q.pop();
    }
    return 0;
}



///class system --> waiting Queue (STL|Ours), Entry LinkedList<customer> (SORT)
///             --> LinkedList<server>
///class server --> Idle/Working, LinkedList<Customer>, LisnkedList<int> (Timestamp)
///class customer --> LinkedList<Interruptions>, Arrival, Departure, ServiceTime
///LinkedList<event_type>  LinkedList<time> (Event, It's Time stamp)
///

