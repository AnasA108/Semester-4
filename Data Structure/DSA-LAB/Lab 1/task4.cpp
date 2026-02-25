#include<iostream>
using namespace std;

class Product
{
	int product_id;
	float price;
public:
	Product()
	{
		product_id = 0;
		price = 0;
	}
	Product(int product_id, float price)
	{
		this->product_id = product_id;
		this->price = price;
	}
	void setter()
	{
		int id;
		cout << "Enter product_id(1000-9999): ";
		cin >> id;
		float p;
		while (id > 9999 || id<1000)
		{
			cout << "Enter product_id again: ";
			cin >> id;
		}

			
		cout << "Enter product price(100.0-5000.0): ";
		cin >> p;
		while (p < 100.0 || p>5000.0)
		{
			cout << "Enter product price again: ";
			cin >> p;
		}
		product_id = id;
		price = p;
	}
	float getprice()
	{
		return price;
	}
	void getter()
	{
		cout << "ID: " << product_id << "| PRICE: " << price;
	}

};
int linear_search(Product *arr[], int k, int n)
{
	int i = 0;
	i == 0;
	while (i < n)
	{
		if (arr[i]->getprice() == k)
		{
			return i;
		}
		else
			i++;
	}
	return -1;
}
void sorting(Product *arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i]->getprice() < arr[j]->getprice())
			{
				Product *temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
int binary_search(Product *arr[], int k, int n)
{
	int high = n - 1;
	int low = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid]->getprice() == k)
		{
			return mid;
		}
		else if (arr[mid]->getprice() > k)
		{
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	if (low > high)
		return -1;


}
int main()
{
	int n1;
	cout << "Enter number of products: ";
	cin >> n1;
	const int n = n1;
	Product** arr = new Product * [n1];
	
	for (int i = 0; i < n; i++)
	{
		arr[i] = new Product();
		cout << "Enter for product " << i + 1 << ": ";
		arr[i]->setter();
	}
	cout << endl << "Products: " << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i]->getter();
		cout << endl;
	}
	cout << "By linear search: " << endl;
	cout << "Enter the desired price: ";
	float k;
	cin >> k;
	int index = linear_search(arr, k, n);
	if (index == -1)
	{
		cout << "No product with the specific price.";

	}
	else
		arr[index]->getter();
	cout << endl;

	sorting(arr, n);
	cout << endl << "After sorting: ";
	for (int i = 0; i < n; i++)
	{
		arr[i]->getter();
		cout << endl;
	}
	cout << "By binary search: " << endl;
	cout << "Enter the desired price: ";
	cin >> k;
	index = binary_search(arr, k, n);
	if (index == -1)
	{
		cout << "No product with the specific price.";

	}
	else
		arr[index]->getter();
	return 0;
}