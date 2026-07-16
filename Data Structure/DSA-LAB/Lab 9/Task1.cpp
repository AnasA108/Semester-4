#include<iostream>
using namespace std;
int count(int num)
{
    if(num==0)
    return 0;
    else
    return 1+count(num/10);
    return 0;
}

int main()
{
    cout<<"count(12345): ";
    cout<<count(12345);
    
}