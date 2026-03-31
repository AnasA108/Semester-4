/***   Q1. Design a template class Counter<T> in C++ that can track and increment a count value of any numeric type.
Your class should:
•	Store a single value of generic type T initialized through the constructor.
•	Provide the following member functions: 
o	increment() → Increases the count value by 1.
o	getValue() → Returns the current count value.
In your main() function, demonstrate the class by:
•	Creating a Counter<int> object with an initial value and calling increment() multiple times, displaying the result after each increment.
•	Creating a Counter<double> object with a decimal starting value and incrementing it, displaying the result.
•	Creating a Counter<float> object and demonstrating the same behavior
***/



#include<iostream>
using namespace std;

template <typename T>
class Counter
{
	T value;
public:

	Counter(T v);
	void increment();
	T getValue();

};

template <typename  T>
Counter<T>::Counter(T v)
{
	value = v;

}

template <typename  T>
void Counter<T>::increment()
{
	value++;
}


template <typename T>
T  Counter<T>::getValue()
{
	return value;
}

int main()
{
	cout << "Integer: " << endl;
	Counter<int> int_counter(4);
	cout << "initial value: " << int_counter.getValue() << endl;
	cout << "After first increment: ";
	int_counter.increment();
	cout << int_counter.getValue()<<endl;
	cout << "After second increment: ";
	int_counter.increment();
	cout << int_counter.getValue() << endl;

	cout <<endl<< "Double: " << endl;
	Counter<double> double_counter(0.5);
	cout << "initial value: " << double_counter.getValue() << endl;
	cout << "After first increment: ";
	double_counter.increment();
	cout << double_counter.getValue() << endl;
	cout << "After second increment: ";
	double_counter.increment();
	cout << double_counter.getValue() << endl;

	cout <<endl<< "Float: " << endl;
	Counter<float> float_counter(10.0);
	cout << "initial value: " << float_counter.getValue() << endl;
	cout << "After first increment: ";
	float_counter.increment();
	cout << float_counter.getValue() << endl;
	cout << "After second increment: ";
	float_counter.increment();
	cout << float_counter.getValue() << endl;
}
