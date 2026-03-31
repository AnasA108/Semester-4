//#include"Stack.h"
//#include<string>
//
//void reverse(string msg)
//{
//	Stack<char>s(msg.length());
//
//	for (int i = 0; i < msg.length(); i++)
//	{
//		s.push(msg[i]);
//	}
//    while (!s.isEmpty())
//	{
//		cout << s.pop();
//	}
//
//}
//bool isPalindrome(string exp)
//{
//	Stack<char> s(exp.length());
//	for (int i = 0; i < exp.length(); i++)
//	{
//		s.push(exp[i]);
//	}
//	for (int i = 0; i < exp.length(); i++)
//	{
//		if (exp[i] != s.pop())
//		{
//			return false;
//		}
//	}
//		return true;
//
//}
//
//
//int main()
//{
//	string name;
//	cout << "Enter a String:";
//	cin >> name;
//	cout << endl;
//	cout << "Reverse is:";
//	 reverse(name);
//	 cout << endl;
//	 if (isPalindrome(name))
//	 {
//		 cout << name<<":Palindrome" << endl;
//	 }
//	 else
//	 {
//		 cout << name<<":Not Palindrome" << endl;
//	 }
//	
//
//	return 0;
//}