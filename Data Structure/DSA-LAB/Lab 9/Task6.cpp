#include<iostream>
using namespace std;
void printrow(int row,int col)
{
    if(col>row)
    return;
    else
    {
    cout<<col<<" ";
    printrow(row,col+1);
   
    }
    return;
}
void printpattern(int n,int row)
{
    if(row>n)
    return;
    else
    {
        printrow(row,1);
        cout<<endl;
        printpattern(n,row+1);
    }
    return;
}
int main()
{
   cout<<"Pattern: "<<endl;
   printpattern(5,1);
   return 0;
}