#include<iostream>
#include<string>
#include "CQueue.h"
using namespace std;

int main()
{
    Queue<string> q(3);
    Queue<string> helper(3);

    string search;

    for (int i = 0; i < 5; i++)
    {
        cout << "Search: ";
        cin >> search;
        if (q.isFull())
        {
            cout << "Drop: " << q.dequeue() << endl;
        }
        q.enqueue(search);
        cout << "History: [";

        while (!q.isEmpty())
        {
            string temp = q.dequeue();
            cout << temp;

            if (!q.isEmpty())
                cout << ", ";

            helper.enqueue(temp);
        }

        cout << "]" << endl;
        while (!helper.isEmpty())
        {
            q.enqueue(helper.dequeue());
        }
    }

    return 0;
}