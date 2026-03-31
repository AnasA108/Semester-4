#include<iostream>
using namespace std;
template <typename T>
class Array
{
	T* arr;
	int size;
	int n;
public:
	Array(int s)
	{
		size = s;
		arr = new T[size];
		n = 0;
	}
	void insert(T v)
	{
		if (n < size)
		{
			arr[n] = v;
			n++;
		}
		else
			cout <<endl<< "limit reached." << endl;
	}
	void remove(T v)
	{
		for (int i = 0;i < n;i++)
		{
			if (arr[i] == v)
				delete arr[i];
		}
	}
	int search(T v)
	{
		int index = -1;
		for (int i = 0;i < n;i++)
		{
			if (arr[i] == v)
				index = i;
		}
		return index;
	}
	T show(int index)
	{
		return arr[index];
	}
};

int main()
{
	Array<int> arr(5);
	arr.insert(10);
	arr.insert(20);
	arr.insert(30);
	arr.insert(40);
	arr.insert(50);
	cout << "Index for element 30: " << arr.search(30);

	Array <float> arr2(3);
	arr2.insert(1.6);
	arr2.insert(2.8);
	arr2.insert(3.5);
	arr2.insert(4.9);

	Array <string> arr3(10);
	arr3.insert("Ali");
	arr3.insert("Ahmad");
	arr3.insert("Hassan");
	if (arr3.search("Ahmad") != -1)
	{
		cout << endl << "Name found.";
	}
	else
		cout << endl << "Name is not on the list;";
		
		return 0;
}