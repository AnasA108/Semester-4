#include<iostream>
#include"Item.h"
#include"Stack.h"
using namespace std;

void scanItem(Stack<Item>& s, string n, float p, int q)   //scanning items and storing them in stack 
{
    if (!s.isFull())
    {
        Item t1(n, p, q);
        s.push(t1);
        cout << endl << "Scanned: " << n << " x" << q << " @ Rs." << p << endl;
    }
    else
        cout << "Limit reached." << endl;
}
void removeItem(Stack<Item>& s)      //removing last item we pusshed in stack
{
    if (!s.isEmpty())
    {
        Item t1 = s.pop();
        cout << "item removed: " << t1.getname() << endl;
    }
    else
        cout << "No item to remove" << endl;
}
void showReceipt(Stack<Item>& s) //showing receipt of the items but not removing them from stack
{
    if (!s.isEmpty())
    {
        double current_bill = 0.00;

        Stack<Item> temp(20);
        while (!s.isEmpty())
        {
            cout << endl << "Current Receipt:" << endl << "------------------------" << endl;
            Item t1 = s.pop();
            temp.push(t1);
            cout << t1.getname() << "\t" << t1.getquantity() << "\tRs." << t1.getquantity() * t1.getprice() << endl;
            current_bill += (t1.getquantity() * t1.getprice());
        }
        cout << "__________________________" << endl;
        cout << "        Current bill= Rs." << current_bill << endl;
        while (!temp.isEmpty())
        {
            s.push(temp.pop());
        }
    }
    else
        cout << "No item in cart." << endl;
}
void checkout(Stack<Item>& s) //getting total amount of the items and also removing them from stack
{
  
    double final_bill = 0.00;
    if (!s.isEmpty())
    {
        cout << "Checkout: " << endl << "-------------------------" << endl;
        while (!s.isEmpty())
        {
            Item t1 = s.pop();
            cout << t1.getname() << "\t" << t1.getquantity() << "\tRs." << t1.getquantity() * t1.getprice() << endl;
            final_bill += (t1.getquantity() * t1.getprice());
        }

        cout << "__________________________" << endl;
        cout << "        Final bill= Rs." << final_bill << endl;
    }
    else
    {
        cout << "No items in cart."<<endl;
        return ;
    }
}

int main()
{
    Stack<Item>  s(20);       //creating stack of item of size 20
    string choice;
    cout << "------------Supermarket Billing System-------------" << endl;
    cout << "A.Scan for scaning item." << endl;
    cout << "B.Remove for removing the last item" << endl;
    cout << "C.Receipt for checking current bill" << endl;
    cout << "D.Checkout for checking final bill" << endl;
    cout << "X.Exit for exiting the billing system" << endl;
    while (true)    //repeating till user exit
    {
        cout << "Enter choice: " << endl;
        cin >> choice;
        if (choice == "Scan"||choice=="A"||choice=="a") //getting product data from user and scanning it into the stack
        {
            string n;
            double p;
            int q;
            cout << "Enter name of he product: ";
            cin >> n;
            cout << "Enter price of the product: ";
            cin >> p;
            cout << "Enter the quantity of the product: ";
            cin >> q;
            scanItem(s, n, p, q);
        }
        else if (choice == "Remove"||choice=="B"||choice=="b")   //removing item
        {
            removeItem(s);
        }
        else if (choice == "Receipt"||choice=="C"||choice=="c") //getting receipt
        {
            showReceipt(s);
        }
        else if (choice == "Checkout"||choice=="D"||choice=="d")    //checking out the bill to pay
        {
            checkout(s);
            cout << endl << "Thank you for shoppping with us" << endl;
        }
        else if (choice == "Exit"||choice=="x"||choice=="X")      //Exiting
        {
            return 0;
        }
    }


    return 0;
}
