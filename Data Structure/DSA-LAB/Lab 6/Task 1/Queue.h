#include <iostream>
using namespace std;

template<class T>
class Queue
{
    T *arr;
    int size;
    int front;
    int rear;

public:

    Queue(int ssize)
    {
        size = ssize;
        arr = new T[size];
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front > rear);
    }

    bool isFull()
    {
        return (rear == size - 1);
    }

    void enqueue(T value)
    {
        if (!isFull())
            arr[++rear] = value;
        else
            cout << "Queue is Full";
    }

    T dequeue()
    {
        T temp = arr[front];
        front++;
        return temp;
    }

    T peek()
    {
        return arr[front];
    }
};