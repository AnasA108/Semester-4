#include<iostream>
using namespace std;
int sum(int num)
{
    if(num==0)
    return 0;
    else
    {
    int  n=num%10;
    return n+sum(num/10);
    }
    return 0;
}
int main()
{
    cout<<endl<<endl<<"Sum(12345): "<<sum(12345);
}