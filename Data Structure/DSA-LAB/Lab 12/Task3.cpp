#include<iostream>
using namespace std;
class Min_Heap
{
    private:
    int *arr;
    int size;
    int n;

    public:
    Min_Heap(int s)
    {
        size=s;
        n=0;
        arr=new int[size];
    }

    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }

    void insert(int v)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]==v)
            {
                cout<<"Duplicate value skipped."<<endl;
                return;
            }
        }

        arr[n]=v;
        int i=n;
        n++;

        int P;

        while(1)
        {
            P=(i-1)/2;

            if(i==0)
            {
                break;
            }

            if(arr[i]<arr[P])
            {
                swap(arr[i],arr[P]);
                i=P;
            }
            else
            {
                break;
            }
        }
    }

    int getel(int index)
    {
        return arr[index];
    }
};

int main()
{
    int arr1[15];

    cout<<"Enter Elements: ";
    for(int i=0;i<15;i++)
    {
        cin>>arr1[i];
    }

    Min_Heap m(20);

    for(int i=0;i<15;i++)
    {
        m.insert(arr1[i]);
    }

    cout<<"Min Heap: ";
    for(int i=0;i<15;i++)
    {
        cout<<m.getel(i)<<" ";
    }
}