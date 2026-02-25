#include<iostream>
using namespace std;
int binary_search(int arr[],int k,int n)
{
	int high = n - 1;
	int low = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == k)
		{
			return mid;
		}
		else if (arr[mid] > k)
		{
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	if(low>high)
		return -1;
	

}
int main()
{
	int arr[8] = { 1,2,3,4,5,6,7,9 };
	int k;
	cout << "Enter the key: ";
	cin >> k;
	int n = 8;
	int index = binary_search(arr, k, n);
	if (index == -1)
	{
		cout << "Element not found.";

	}
	else
		cout << "Element found at index " << index;
	return 0;
}