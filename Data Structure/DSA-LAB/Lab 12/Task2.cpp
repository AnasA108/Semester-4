#include<iostream>
using namespace std;
class Max_Heap
{
    private:
    int *arr;
    int size;
    int n;
    public:
    Max_Heap(int s)
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
            if(arr[i]>arr[P])
            {
            swap(arr[i],arr[P]); 
            i=P;
            }
            else
            break;
        }
    }
void extractMax()
   {
    if(n==0)
    {
        cout<<"Heap is Empty";
        return;
    }
    int max=arr[0];
    arr[0]=arr[n-1];
    n--;

    int i=0;

    while(1)
    {
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;

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
    Max_Heap m(20);
    for(int i=0;i<15;i++)
    {
        m.insert(arr1[i]);
    }
    for(int i=0;i<15;i++)
    {
        cout<<m.getel(i)<<" ";
    }
    cout<<"Deleting root : ";
    m.extractMax();
    for(int i=0;i<15;i++)
    {
        cout<<m.getel(i)<<" ";
    }
}
