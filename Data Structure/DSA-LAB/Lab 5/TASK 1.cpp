#include<iostream>
using namespace std;
#include <iostream>
using namespace std;

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
    char infix[50];
    cout<<"Enter infix: ";
    cin.getline(infix,50);
    string postfix="";
    Stack <char> s(50);
    int k=0,top=-1;
    for(int i=0;infix[i]!='\0';i++)
    {
    char ch=infix[i];
    if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
    {
        postfix+=ch;
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

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
