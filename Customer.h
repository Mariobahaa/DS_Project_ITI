#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <queue>
#include <list>


using namespace std;

class Customer
{
    list<int> Interruptions;
    int Departure, ServiceTime;
    public:
    int Arrival;
    //Customer(list<int>Intr, int arrival, int departure, int st){
    Customer(int arrival, int st){

        //Interruptions = Intr;
        Arrival = arrival;
        ServiceTime= st;
        Departure = 0;
    }

};

#endif // CUSTOMER_H
