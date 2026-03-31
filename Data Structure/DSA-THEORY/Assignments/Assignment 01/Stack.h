#include <iostream>
using namespace std;

template<class T>
class Stack 
{
  	T *arr;
	int size;
	int top;  //this is a replacement
  
  	public:
  
 	 Stack(int ssize)
  	{
      		size=ssize;
	                   arr=new int[size];
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

/*
Sample run discussed in class , nort required for this assignment
int main()
{
    Stack s(3);
    s.push(3);
    s.push(7);
    s.push(20);
    
    if(s.isEmpty())
        cout<<"Your stack is empty"<<endl;
    else
    {
        int value=s.pop();
        cout<< " popped value is : "<<value<<endl;
        
    }
    
    if(!s.isEmpty())
        cout<<s.peek()<<endl;

    return 0;
}*/