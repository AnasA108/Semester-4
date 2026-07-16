#include<iostream>
using namespace std;
 #include"Order.h"
  Order::Order()
    {
      orderID=0;
      customerName="";
      item="";
      quantity=0;
    }  // default constructor
    Order::Order(int id, string name, string it, int qty)  // parameterized constructor
    {
        orderID=id;
        customerName=name;
        item=it;
        quantity=qty;
    }
    void Order::display()                                   // print formatted order line as mentioned in the output
    {
        cout<<endl<<"Fulfilled || Order #"<<orderID
        <<" || Customer: "<<customerName<<" || Item: "
        <<item<<" || Qty: "<<quantity<<endl;
    
     }