#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void heapify(int arr[],int n,int i)
{
    int largest=i;

    while(1)
    {
        int left=2*i+1;
        int right=2*i+2;

        largest=i;

        if(left<n && arr[left]>arr[largest])
        {
            largest=left;
        }

        if(right<n && arr[right]>arr[largest])
        {
            largest=right;
        }

        if(largest!=i)
        {
            swap(arr[i],arr[largest]);
            i=largest;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter Size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }

    cout<<"Max Heap: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}