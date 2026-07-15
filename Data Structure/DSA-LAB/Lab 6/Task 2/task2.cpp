#include<iostream>
#include "CQueue.h"
using namespace std;
void reverse(int arr[])
{
	Queue <int> q(20);
	for (int i = 0; i < 5; i++)
	{
		q.enqueue(arr[i]);
	}
	for (int i = 4; i >= 0; i--)
	{
		arr[i] = q.dequeue();
	}
}
int main()
{
	int arr[5] = { 1,2,3,4,5 };
	cout << "Old array: ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
	reverse(arr);
	cout << "New array: ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Enter elements:";
	for (int i = 0;i < 5;i++)
	{
		cin >> arr[i];
	}
	cout << endl << "Old array: ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
	reverse(arr);
	cout << "Old array: ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
}