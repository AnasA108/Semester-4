#include<iostream>
#include"Queue.h"
using namespace std;

// global function moving average prototype
void init_array(int arr[], const int size);
void movingAverage(int arr[], const int size, const int k); //here k=window_size

int main()
{
    const int size = 10;
    int arr[size];
    init_array(arr, size);
    // prepare parameters for  the call of movingAverage() function 
    movingAverage(arr, size, 3);


    return 0;
}
void init_array(int arr[], const int size)
{
    cout << "Enter the elements: ";                      //getting elements of array by user
    for (int i = 0;i < size;i++)
    {
        cin >>arr[i];
    }
}
void movingAverage(int arr[], const int size, const int k)
{
    cout <<endl<< "Moving Average: "<<endl;
    Queue<int> q(k);
    int sum = 0;
    int w = 1;

    for (int i = 0;i <size;i++)          //creating loop for all elements of array
    {
        if (q.isFull())                    //removing old element when i becomes equal or greater to queue so we can enter the next element
        {
            sum -=q.dequeue();
        }
        q.enqueue(arr[i]);
        sum += arr[i];                  //storing sum of element of each window
        
        if (i >= k - 1)                  //calculating the average of queue when filled with elements
        {
            cout << "Window "<<w<<": [";
            int c = k;
            for (int j = 0;j < c;j++)       //created loop for showing elements of the queue
            {
                int val = q.dequeue();       //temporary removal of element to display 
                cout << val;
                if (j < c - 1)
                {
                    cout <<",";     //for , between the elements
                }
                q.enqueue(val);          //getting value back to queue
            }
            cout <<"]";
            cout <<" ->Average: " << (float)sum / k << endl;        //displaying the average for each window
            w++;
        }
    }

           
        


    
}