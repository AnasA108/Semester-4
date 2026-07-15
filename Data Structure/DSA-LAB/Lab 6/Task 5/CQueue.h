#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T* arr;
    int size;
    int front;
    int rear;
    int count;

public:

    Queue(int s)
    {
        size = s;
        arr = new T[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(T value)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return T();
        }

        T temp = arr[front];
        front = (front + 1) % size;
        count--;

        return temp;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return T();
        }

        return arr[front];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == size;
    }
};
