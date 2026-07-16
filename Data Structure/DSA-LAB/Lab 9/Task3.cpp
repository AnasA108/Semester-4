#include<iostream>
using namespace std;
string removefirst(string s)
{
    string temp="";

    for(int i=1;s[i]!='\0';i++)
    {
        temp=temp+s[i];
    }

    return temp;
}
string reverse(string s)
{
    if(s=="\0")
    return "";
    else
    {
        char n=s[0];
        
        return reverse(removefirst(s))+n;
    }
    return "";
}
int main()
{
    cout<<"reverse(hello):"<<reverse("hello");
   return 0;
}