#include<iostream>
using namespace std;
int linear_search(int arr[], int k,int n)
{
	int i = 0;
	i == 0;
	while (i < n)
	{
		if (arr[i] == k)
		{
			return i;
		}
		else
			i++;
	}
	return -1;
}
int main()
{
	int k;
	cin >> k;
	int arr[8] = { 1,6,2,3,4,9,8,7 };
	int n = 8;
	int i=linear_search(arr, k,8);
	if (i == -1)
	{
		cout << "Element not found";

	}
	else
	{
		cout << "Element found at index "<<i;
	}
	return 0;
}