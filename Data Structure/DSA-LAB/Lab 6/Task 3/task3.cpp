#include<iostream>
#include<string>
#include "CQueue.h"
using namespace std;

int main()
{
    Queue<string> q(10);
    string command, doc;

    while (true)
    {
        cout << "Enter command (ADD / PRINT / EXIT): ";
        cin >> command;

        if (command == "ADD")
        {
            cout << "Enter document name: ";
            cin >> doc;

            if (q.isFull())
            {
                cout << "Queue is full. Cannot add." << endl;
            }
            else
            {
                q.enqueue(doc);
            }
        }

        else if (command == "PRINT")
        {
            if (q.isEmpty())
            {
                cout << "No documents in queue." << endl;
            }
            else
            {
                cout << "Printing: " << q.dequeue() << endl;
            }
        }

        else if (command == "EXIT")
        {
            break;
        }

        else
        {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}