//#include"Stack.h"
//#include<string>
//
//bool isMatchingpair(char open,char close)
//{
//	if (open == '(' && close == ')')
//	{
//		return true;
//    }
//	if (open == '{' && close == '}')
//	{
//		return true;
//	}
//	if (open == '[' && close == ']')
//	{
//		return true;
//	}
//	return false;
//}
//bool isBalanced(string expr)
//{
//	Stack<char>s1(expr.length());
//	for (int i = 0; i < expr.length(); i++)
//	{
//		char ch = expr[i];
//		if (ch == '(' || ch == '{' || ch == '[')
//		{
//			s1.push(ch);
//		}
//		else if (ch == ')' || ch == '}' || ch == ']')
//		{
//			if (s1.isEmpty())
//			{
//				return false;
//			}
//			char top = s1.pop();
//
//			if (isMatchingpair(ch, top))
//			{
//				return true;
//			}
//		}
//	}
//	return s1.isEmpty();
//}
//
//int main()
//{
//	string test1="[{()}]";
//	string test2="[{(}]";
//
//	cout << test1 << "->" << (isBalanced(test1) ? "Balnced" : "Not Balanced") << endl;
//	cout << test2 << "->" << (isBalanced(test2) ? "Balanced" : "Not Balanced") << endl;
//	
//	string custom;
//	cout << "Enter any expression:";
//	cin >> custom;
//	cout << custom << "->" << (isBalanced(custom) ? "Balanced" : "Not Balanced") << endl;
//    return 0;
//}