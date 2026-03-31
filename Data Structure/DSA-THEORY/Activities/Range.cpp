#include<iostream>
using namespace std;
template <typename T>
class Range
{
	T a;
	T b;
public:
	Range(T a1, T b1)
	{
		
		a = a1;
		b = b1;
		cout << "Range " << a << " to " << b << endl;
	}
  
	bool check(T value)
	{
		if (value >= a && value <= b)
			return true;
		else
			return false;
	}
	void inrange(T value)
	{
		
		if (check(value) == true)
		{
			cout << value << " in range: Yes"<<endl;
		}
		else
			cout << value << " in range: No"<<endl;
	}
};

int main()
{
	cout << "Int: " << endl;
	Range <int> R1(3, 9);
	R1.inrange(5);
	R1.inrange(11);

	cout <<endl<< "Double: " << endl;
	Range <double> R2(3.5, 12.3);
	R1.inrange(12.4);
	R1.inrange(3.6);

	cout <<endl<< "Char: " << endl;
	Range <char> R3('A', 'F');
	R3.inrange('E');

	R3.inrange('H');
	return 0;
}