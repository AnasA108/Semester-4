#include<iostream>
using namespace std;
template <typename T>
class Range
{
	T a;
	T b;
public:
	Range(T a1, T b1);
	bool check(T value);
	void inrange(T value);
};
template <typename T>
Range<T>::Range(T a1, T b1)
{

	a = a1;
	b = b1;
	cout << "Range " << a << " to " << b << endl;
}
template <typename T>
bool  Range<T>::check(T value)
{
	if (value >= a && value <= b)
		return true;
	else
		return false;
}
template <typename T>
void Range<T>::inrange(T value)
{

	if (check(value) == true)
	{
		cout << value << " in range: Yes" << endl;
	}
	else
		cout << value << " in range: No" << endl;
}