#include<iostream>
#include "Stack.h"
using namespace std;
int main()
{
    Stack<string> forwardpage(20);
    Stack<string> backpage(20);
    string command, url;
    string currentpage = "";

    while (true)
    {
        cin >> command;

        if (command == "Visit")
        {
            cin >> url;

            if (currentpage != "")
                backpage.push(currentpage);

            currentpage = url;
            while (!forwardpage.isEmpty())
                forwardpage.pop();

            cout << "Current: " << currentpage << endl;
        }

        else if (command == "Back")
        {
            if (backpage.isEmpty())
            {
                cout << "Nothing to go back to." << endl;
            }
            else
            {
                forwardpage.push(currentpage);
                currentpage = backpage.pop();
                cout << "Current->" << currentpage << endl;
            }
        }

        else if (command == "Forward")
        {
            if (forwardpage.isEmpty())
            {
                cout << "Nothing to go forward to." << endl;
            }
            else
            {
                backpage.push(currentpage);
                currentpage = forwardpage.pop();
                cout << "Current->" << currentpage << endl;
            }
        }

        else if (command == "Exit")
        {
            break;
        }
        else
        {
            cout<<"Wrong command.";
            continue;
        }
    }

    return 0;
}