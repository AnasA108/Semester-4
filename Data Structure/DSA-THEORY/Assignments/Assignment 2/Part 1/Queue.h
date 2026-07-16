#ifndef QUEUE_H
#define QUEUE_H

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
    // Constructor: initializes queue of given size
    Queue(int s)
    {
        size = s;
        arr = new T[size];
        front = 0;
        rear  = -1;
         count=0;
    }

    // Destructor: frees dynamically allocated memory
    ~Queue()
    {
        delete[] arr;
    }

    // Enqueue: adds element to the rear of the queue
    void Enqueue(T value)
    {
        if (isFull())
        {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
    }

    // Dequeue: removes and returns element from the front
     T Dequeue()
    {
          T value = arr[front];
          front = (front + 1) % size;
          count--;
          return value;
    }

    // Peek: returns front element without removing it
    T Peek()
    {
           return arr[front];
    }

    // isEmpty: returns true if queue has no elements
    bool isEmpty()
    {
        return count == 0;
    }

    // isFull: returns true if queue has reached capacity
    bool isFull()
    {
        return  count == size;
    }

};

#endif // QUEUE_H