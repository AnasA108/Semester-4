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
int main()
{
    string infix;
    cout<<"Enter infix: ";
    cin>>infix;
    string postfix="";
    Stack <char> s(50);
    int k=0,top=-1;
    string rev=reverseStr(infix);
    for(int i=0;rev[i]!='\0';i++)
    {
    char ch=rev[i];
    if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
    {
        postfix+=ch;
    }
     else if (ch == ')')
    {
        s.push(ch);
    }
    else if (ch == '(')
    {
        while (!s.isEmpty() && s.peek() != ')')
        {
            postfix += s.pop();
        }
        s.pop();
    }
    else
    {
        while(!s.isEmpty()&&precedence(s.peek())>=precedence(ch))
        {
            postfix+=s.pop();
        }
        s.push(ch);
    }
    } 
      while (!s.isEmpty())
    {
        postfix += s.pop();
    }   
  string prefix=reverseStr(postfix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
