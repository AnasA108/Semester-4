#include"Stack.h"

int getPrecedence(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	return 0;
}
bool isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
string infixToPostfix(string exp)
{
	Stack<char>s(exp.length());
	string postfix = "";

	for (int i = 0; i < exp.length(); i++)
	{
		char ch = exp[i];
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= 0 && ch <= 9))
		{
			postfix += ch;
	    }
		else if (isOperator(ch))
		{
			while (!s.isEmpty() && getPrecedence(s.returnsTop()) >= getPrecedence(ch))
			{
				postfix += s.pop();
			}
			s.push(ch);
		}
	}

	while (!s.isEmpty())
	{
		postfix += s.pop();
	}

	return postfix;
}
int main()
{
	string test = "A+B*C/";
	cout << "Infix:" << test << endl;
	cout << "PostFix:" << infixToPostfix(test) << endl;

	return 0;
}