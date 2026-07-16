#pragma once
#include <iostream>
template <class T>
class Queue
{
private:
    T arr[100];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return rear < front;
    }

    bool isFull()
    {
        return rear == 99;
    }

    void enqueue(T val)
    {
        if (!isFull())
        {
            rear++;
            arr[rear] = val;
        }
    }

    T dequeue()
    {
        return arr[front++];
    }
};
