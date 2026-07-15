#include<iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;
#include<string>
bool palindrome(string word)
{
    Stack <char> s(20);
    Queue <char> q(20);
    for(int i=0;word[i]!='\0';i++)
    {
        s.push(word[i]);
        q.enqueue(word[i]);
    }
    string rev_word;
    while(!s.isEmpty())
    {
        rev_word+=s.pop();
    }
    bool check=true;
    for(int i=0;rev_word[i]!='\0';i++)
    {
        if(q.dequeue()!=rev_word[i])
        check=false;
    }
    return check;
}
int main()
{
    
    string word;
    cout<<"Enter the word: "<<endl;
    cin>>word;
    bool pal=palindrome(word);
    if(pal==true)
    {
        cout<<"Word is a palindrome.";
    }
    else
    {
        cout<<"Word is not a palindrome.";
    }
    return 0;
}