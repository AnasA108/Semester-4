#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	int size;
	int top;
	T* arr;
public:
	Stack(int s);
	bool isFull();
	bool isEmpty();
	void push(T value);
	T pop();
	T returnsTop();
	~Stack();
};
template<class T>
Stack<T>::Stack(int s)
{
	size = s;
	top = -1;
	arr = new T[size];
}
template<class T>
bool Stack<T>::isFull()
{
	return (top == size - 1);
}
template<class T>
bool Stack<T>::isEmpty()
{
	return (top == -1);
}
template<class T>
void Stack<T>::push(T value)
{
	if (isFull())
	{
		cout << "Stack Overflow Can't push" << value << endl;
	}
	arr[++top] = value;
}
template<class T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "\nStack is empty" << endl;
	}
	return arr[top--];
}
template<class T>
T Stack<T>::returnsTop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty" << endl;
	}
	return arr[top];
}
template<class T>
Stack<T>::~Stack()
{
	delete[]arr;
}