//#include"Stack.h"
//
//void decimattoBinary(int n)
//{
//	if (n == 0)
//	{
//		cout << "0" << endl;
//	}
//
//	Stack<int> s1(32);
//	while (n > 0)
//	{
//		s1.push(n % 2);
//		n = n / 2;
//	}
//	while (!s1.isEmpty())
//	{
//		cout << s1.pop();
//	}
//	cout << endl;
//}
//
//int main() 
//{
//	int num;
//	cout << "Enter any integer number:";
//	cin >> num;
//	cout << endl;
//	cout << "Binary Form:";
//	decimattoBinary(num);
//	return 0;
//}