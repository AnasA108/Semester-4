/***  Q2. Write a template class Array<T> in C++ that can store exactly 5 elements of any data type.
Your class should provide the following functionality:
•	set(int index, T value) → Stores a value at the given index. If the index is out of range, display an appropriate message.
•	get(int index) → Returns the value at the given index. If the index is out of range, display an appropriate message.
•	print() → Displays all 5 elements in a single line.
In your main() function, demonstrate the class by:
•	Creating an Array<int> object, storing 5 integer values and printing them.
•	Creating an Array<double> object, storing 5 decimal values and printing them.
**/

#include<iostream>
using namespace std;
template <typename T>
class Array
{
	T elements[5];
public:
	Array()
	{
		for (int i = 0;i < 5;i++)
		{
			elements[i] = 0;
		}
	}
	void set(int index, T value);
	T get(int index);
	void print();
};
template <typename T>
void Array <T>::set(int index, T value)
{
	if (index >= 0 && index < 5)
		elements[index] = value;
	else
		cout << "index out of range";
}
template <typename T>
T Array <T>::get(int index)
{
	if (index >= 0 && index <= 4)
		return elements[index];
	else
		return 0;
}
template <typename T>
void Array <T>::print()
{
	cout << "elements:  ";
	for (int i = 0;i < 5;i++)
	{
		cout << elements[i] << " ";
	}
}
int main()
{
	cout << "Integer type data : " << endl;
	Array<int> c1;
	c1.set(0, 0);
	c1.set(1, 1);
	c1.set(2, 3);
	c1.set(3, 5);
	c1.set(4, 7);
	
	cout << "elements by getter: ";
	cout << c1.get(0)<<" ";
	cout << c1.get(1)<<" ";
	cout << c1.get(2)<<" ";
	cout << c1.get(3)<<" ";
	cout << c1.get(4)<<endl;
	cout << "By print function: "<<endl;
	c1.print();
	cout << endl<<"Double type data: " << endl;
	Array <double> c2;
	c2.set(0, 0.5);
	c2.set(1, 1.5);
	c2.set(2, 2.5);
	c2.set(3, 3.5);
	c2.set(4, 4.5);
	cout << "elements by getter: ";
	cout << c2.get(0) << " ";
	cout << c2.get(1) << " ";
	cout << c2.get(2) << " ";
	cout << c2.get(3) << " ";
	cout << c2.get(4) << endl;
	cout << "By print function: " << endl;
	c2.print();
        return 0;
}