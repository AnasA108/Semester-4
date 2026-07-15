#include<iostream>
#include "CQueue.h"
using namespace std;

int main()
{
    int arr[5] = { 101, 102, 103, 102, 104 };

    Queue<int> mainQ(10);
    Queue<int> helperQ(10);

    for (int i = 0; i < 5; i++)
    {
        int current = arr[i];
        bool found = false;

        cout << "Checking " << current << " ... ";

        // Scan mainQ
        while (!mainQ.isEmpty())
        {
            int temp = mainQ.dequeue();

            if (temp == current)
            {
                found = true;
            }

            helperQ.enqueue(temp);
        }

        // Restore mainQ
        while (!helperQ.isEmpty())
        {
            mainQ.enqueue(helperQ.dequeue());
        }

        // Check result
        if (found)
        {
            cout << "DUPLICATE FOUND: " << current << endl;
        }
        else
        {
            mainQ.enqueue(current);
            cout << "Added." << endl;
        }
    }
    cout << "\nUnique roll numbers: ";

    while (!mainQ.isEmpty())
    {
        cout << mainQ.dequeue() << " ";
    }

    return 0;
}