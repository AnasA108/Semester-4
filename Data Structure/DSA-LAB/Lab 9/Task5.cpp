#include<iostream>
using namespace std;
bool palindrome(string s,int start,int end)
{
    if(start>=end)
    return true;
    if(s[start]!=s[end])
    return false;
     else
     {
         return palindrome(s,start+1,end-1);
     }
     return true;
}
int main()
{
    cout<<"Palindrome(Madam): ";
   if(palindrome("madam",0,4)==true)
   cout<<"True";
   else
   cout<<"False";
   return 0;
}