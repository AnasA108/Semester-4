#include<iostream>
using namespace std;
int binary_search(int arr[],int low,int high,int v)
{
    if(low>high)
    return -1;
    int mid=(low+high)/2;
    if(arr[mid]==v)
    return mid;
    if(arr[mid]>v)
    {
    return binary_search(arr,low,mid-1,v);
    }
    if(arr[mid]<v)
    {
    return binary_search(arr,mid+1,high,v);
    }
    return 0;
}
int main()
{
   cout<<"Array: "<<endl;
   int arr[5]={2,5,7,9,11};
   for(int i=0;i<5;i++)
   cout<<arr[i]<<" ";
   cout<<endl<<"Searching for 9:\t";
   int i=binary_search(arr,0,5,9);
   if(i!=-1)
   {
       cout<<"Found at index "<<i;
   }
   else
   cout<<"Not found!";
   cout<<endl<<"Searching for 12:\t";
   i=binary_search(arr,0,5,12);
   if(i!=-1)
   {
       cout<<"Found at index "<<i;
   }
   else
   cout<<"Not found!";
   cout<<endl<<"Searching for 7:\t";
   i=binary_search(arr,0,5,7);
   if(i!=-1)
   {
       cout<<"Found at index "<<i;
   }
   else
   cout<<"Not found!";
   return 0;
}