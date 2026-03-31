/***  Q3. Design a template class Comparator<T> in C++ that can compare two values of any data type.
Your class should:
•	Store two values of generic type T passed through the constructor.
•	Provide the following member functions: 
o	isGreater() → Returns true if the first value is greater than the second.
o	isLess() → Returns true if the first value is less than the second.
o	isEqual() → Returns true if both values are equal.
In your main() function, demonstrate the class by:
•	Creating a Comparator<int> object with two integer values and displaying the comparison results.
•	Creating a Comparator<double> object with two decimal values and displaying the comparison results.
•	Creating a Comparator<char> object with two characters and displaying the comparison results.
**/

#include<iostream>
using namespace std;
template <typename T>
class comparator
{
	T a;
	T b;
public:
	comparator(T a1, T b1)
	{
		a = a1;
		b = b1;
	}
	bool isgreater()
	{
		if (a > b)
		{
			return true;
		}
		return false;
	}
	bool issmaller()
	{
		if (a < b)
		{
			return true;
		}
		return false;
	}
	bool isequal()
	{
		if (a == b)
			return true;
		else
			return false;
	}
};
int main()
{
	cout << "Integer type comparison: " << endl;
	comparator <int> c1(2,3);
	cout << "Greater: ";
	if (c1.isgreater() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";
	cout <<endl<< "Smaller: ";
	if (c1.issmaller() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";

	cout << endl << "Equal: ";
	if (c1.isequal() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";
	cout << endl;
	cout << "double type comparison: " << endl;
	comparator <double> c2(2.7,3.3);
	cout << "Greater: ";
	if (c2.isgreater() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";
	cout <<endl<< "Smaller: ";
	if (c2.issmaller() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";

	cout << endl << "Equal: ";
	if (c2.isequal() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";

	cout <<endl<< "Char type comparison: " << endl;
	comparator <char> c3('Z', 'A');
	cout << "Greater: ";
	if (c3.isgreater() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";
	cout << endl << "Smaller: ";
	if (c3.issmaller() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";

	cout << endl << "Equal: ";
	if (c3.isequal() == true)
	{
		cout << "Yes";
	}
	else
		cout << "No";
	return 0;
}
