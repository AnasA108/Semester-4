#pragma once
#include <iostream>
template <class T>
class Stack
{
private:
    T arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 99;
    }

    void push(T val)
    {
        if (!isFull())
        {
            top++;
            arr[top] = val;
        }
    }

    T pop()
    {
        return arr[top--];
    }

    T Top()
    {
        return arr[top];
    }
};
