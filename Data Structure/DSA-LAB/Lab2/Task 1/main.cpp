#include<iostream>
#include"header.h"
using namespace std;
int main()
{
	Calculator <int> c1(3,4);
	Calculator <double> c2(2.145, 0);

	cout << endl << "    ---Integer calculator---   " << endl;
	c1.show();
	cout << endl << "  ---Double calculator---" << endl;
	c2.show();
	cout << "------------------------";
}
