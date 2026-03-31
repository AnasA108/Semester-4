#include<iostream>
using namespace std;
#include <iostream>
using namespace std;
string reverseStr(string str)
{
    string rev = "";
    for (int i = str.length() - 1; i >= 0; i--)
        rev += str[i];
    return rev;
}
template<class T>
class Stack 
{
  	T *arr;
	int size;
	int top;
  
  	public:
  
 	 Stack(int ssize)
  	{
      		size=ssize;
	                   arr=new T[size];
		top=-1;
	  }
  
  	bool isEmpty()
  	{
		      return (top==-1);
      
  	}
  
  	bool isFull()
  	{
		     return (top==size-1) ;
      
  	}
  	void push(T value)
	{
		      if(!isFull())
		      arr[++top]=value;
      		      else
		             cout<<"Stack is Full";
	}
  
  	T pop()
  	{
		        T temp=arr[top];
		        top--;
		        return temp;
     
  	}
 
 	 T peek()
  	{
      		return arr[top];
  	}
  
};
int precedence(char ch)
{
    if(ch=='+'||ch=='-')
    return 1;
    else if(ch=='*'||ch=='/')
    return 2;
    return 0;
}
int evaluatePostfix(string ex)
{
    Stack<int> s(50);

    for (int i = 0; ex[i] != '\0'; i++)
    {
        char ch = ex[i];
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else
        {
            int op2 = s.pop();
            int op1 = s.pop();

            int result;

            if (ch == '+') result = op1 + op2;
            else if (ch == '-') result = op1 - op2;
            else if (ch == '*') result = op1 * op2;
            else if (ch == '/') result = op1 / op2;

            s.push(result);
        }
    }

    return s.pop();
}
int main()
{
    string ex;
    cout<<"Enter expression:";
    cin>>ex;
    cout<<evaluatePostfix(ex);
    return 0;
}
