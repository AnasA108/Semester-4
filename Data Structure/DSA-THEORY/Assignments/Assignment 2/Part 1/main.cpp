#include <iostream>
#include <string>
#include "Queue.h"
#include "Order.h"
using namespace std;

//This program gets the orderid customer name item and its item in a class and than stores in a circuler queue and
//than process the orders and than counts the number of orders processed 
void processOrders(Queue<Order>& q)   // you will implement this
{
    if(!q.isEmpty())
    {
    int c=0;
    while (!q.isEmpty())
    {
        Order temp = q.Dequeue();
        temp.display();
        c++;
    }
    cout<<endl<<"Total orders fulfilled: "<<c;
    }
    else
    {
        cout<<endl<<"No pending orders"<<endl;
    }
}
int main()
{
    Queue<Order> q(10);
  cout<<"---Placing orders---"<<endl<<endl;
    // --- starter: one object to verify your Order.cpp compiles ---
    Order o1(1, "Ali", "Pizza", 2);
    q.Enqueue(o1);
    cout << "Order placed: " << o1.customerName
         << " ordered " << o1.item
         << " x" << o1.quantity << endl;
     Order o2(2,"Ahmad","tea",4);
     q.Enqueue(o2);
     cout<<"Order placed: "<<o2.customerName
     <<" ordered "<< o2.item
     <<" x"<<o2.quantity<<endl;
     Order o3(3,"Haseeb","Sandwitch",4);
     q.Enqueue(o3);
     cout<<"Order placed: "<<o3.customerName
     <<" ordered "<< o3.item
     <<" x"<<o3.quantity<<endl;
     Order o4(4,"Shees","Cappuccino",2);
     q.Enqueue(o4);
     cout<<"Order placed: "<<o4.customerName
     <<" ordered "<< o4.item
     <<" x"<<o4.quantity<<endl;
     Order o5(5,"Ali","Milk",3);
     q.Enqueue(o5);
     cout<<"Order placed: "<<o5.customerName
     <<" ordered "<< o5.item
     <<" x"<<o5.quantity<<endl;
     cout<<endl<<"---Processing orders---"<<endl;
     processOrders(q);
     processOrders(q);
    // TODO: enqueue o2..o5, call processOrders(), isEmpty() check,
    //       and the runtime-input loop for 3 more orders.
    int oid;
    string cname;
    string it;
    int qty;
    for(int i=0;i<3;i++)       //run time loop for data entry
    {
        cout<<"Enter order id: ";
        cin>>oid;
        cout<<"Enter customer name: ";
        cin>>cname;
        cout<<"Enter item: ";
        cin>>it;
        cout<<"Enter quantity: ";
        cin>>qty;
        Order o(oid,cname,it,qty);
        q.Enqueue(o);
     cout<<"Order placed: "<<o.customerName
     <<" ordered "<< o.item
     <<" x"<<o.quantity<<endl;
    }
    cout<<"---Processing orders---"<<endl;
   processOrders(q);
   
    return 0;
}