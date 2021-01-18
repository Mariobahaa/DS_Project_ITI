#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#include "System.h"
#include "Customer.h"
#include "Server.h"


using namespace std;
int main()
{

    cout << "\n\t\t\t\t\t\t     Welcome!"<<endl << endl;
    int CustomerNum, ServersNum;
    cout << "Enter Number of Customers" <<endl;
    cin >> CustomerNum;
    cout << "Enter Number of Servers" << endl;
    cin >> ServersNum;

    list<Customer*> customers;
    for(int i=0; i<CustomerNum; i++)
    {
        cout << "Enter Customer " << i+1 << " 's Data"<<endl;
        int arrival, serviceTime;
        cout << "Enter Customer " << i+1 << " 's Arrival Time"<<endl;
        cin >> arrival;
        cout << "Enter Customer " << i+1 << " 's Service Time"<<endl;
        cin >> serviceTime;

        if(arrival>=0 && serviceTime>=1)
            customers.push_back(new Customer(arrival,serviceTime,i+1));
        else cout<< "\nNot a valid customer data for customer C"<<i+1<<"\n\n";
    }

    list<Server*> servers;
    for(int i=0; i<ServersNum; i++)
    {
        servers.push_back(new Server(i+1));
    }

    list<pair<int,Server*>> interruptions;
    int interNum;
    int time;
    list<Server*>::iterator it;
    it= servers.begin();
    for(int i=0; i<ServersNum; i++)
    {
        cout << "Enter Number of Interruptions of Server " << i+1 <<endl;
        cin >> interNum;
        for(int i=0; i<interNum; i++)
        {
            cout << "Enter Time of Interruption " << i+1 << endl;
            cin >> time;
            pair <int, Server*> p(time,*it);
            if(time>=0)
                interruptions.push_back(p);
        }
        if(it!=servers.end())
            it++;
    }

    System Sys(customers,servers,interruptions,ServersNum,CustomerNum);
    Sys.Start();
    Sys.Report();

    list<Server*>::iterator sit;
    for(sit=servers.begin();sit!=servers.end();++sit)
    {
        delete *sit;
    }


    list<Customer*>::iterator cit;
    for(cit=customers.begin();cit!=customers.end();++cit)
    {
        delete *cit;
    }

    return 0;
}
