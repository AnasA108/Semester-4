//#include"Stack.h"
//
//void sortedstack(Stack<int>& s1,int n)
//{
//	Stack<int>temp(n);
//	while (!s1.isEmpty())
//	{
//		int current = s1.pop();
//		while (!temp.isEmpty() && temp.returnsTop()>current)
//		{
//			s1.push(temp.pop());
//		}
//		temp.push(current);
//	}
//	while (!temp.isEmpty())
//	{
//		s1.push(temp.pop());
//	}
//}
//int main()
//{
//	Stack<int>s(10);
//	s.push(3);
//	s.push(1);
//	s.push(4);
//	s.push(2);
//
//	cout << "Sorted Stack (top to bottom):";
//	sortedstack(s, 10);
//
//	while (!s.isEmpty())
//	{
//		cout<< s.pop() << " ";
//	}
//
//	return 0;
//}