#pragma once
#include<iostream>
using namespace std;

class Item {
    string name;
    float  price;
    int    quantity;

public:
    Item(string n, float p, int q)
    {
        name = n;
        price = p;
        quantity = q;
    }
    Item()
    {
        name = "";
        price = 0.0;
        quantity = 0;

    }
    string getname()            //getting name
    {
        return name;
    }
    float getprice()      //getting price
    {
        return price;
    }
    int getquantity()      //getting quantity
    {
        return quantity;
    }
};
