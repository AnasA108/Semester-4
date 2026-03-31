#include<iostream>
using namespace std;
template <typename T>
class Array
{
	T* arr;
	int size;
	int n;
public:
	Array(int s)
	{
		size = s;
		arr = new T[size];
		n = 0;
	}
	void insert(T v)
	{
		if (n < size)
		{
			arr[n] = v;
			n++;
		}
		else
			cout << endl << "limit reached." << endl;
	}
		void remove(T v)
		{
			for (int i = 0; i < n; i++)
			{
				if (arr[i] == v)
				{
					for (int j = i; j < n - 1; j++)
						arr[j] = arr[j + 1];

					n--;
					break;
				}
			}
		}
	int search(T v)
	{
		int index = -1;
		for (int i = 0;i < n;i++)
		{
			if (arr[i] == v)
				index = i;
		}
		return index;
	}
	T show(int index)
	{
		return arr[index];
	}
};
class Product
{
	int product_id;
	string product_name;
	float price;
	int quantity;
public:
	Product()
	{
		product_id = 0;
	}
	Product(int pid)
	{
		product_id = pid;
	}
	Product(int pid, string pn, float p, int q)
	{
		product_id = pid;
		product_name = pn;
		price = p;
		quantity = q;
	}
	void display()
	{
		cout << endl << product_id << "\t" << product_name << "\t" << price << "\t" << quantity << endl;
	}
	bool operator==(Product& obj)
	{
		return (product_id == obj.product_id);
	}
	friend ostream& operator<<(ostream& out, Product& obj);
};
ostream& operator<<(ostream& out, Product& obj)
{
	out << endl << obj.product_id << "\t" << obj.product_name << "\t" << obj.price << "\t" << obj.quantity << endl;
	return out;
}
int main()
{
	Array<Product> arr(10);
	Product p1(1, "tablet", 300, 10);
	Product p2(2, "phone", 600, 30);
	Product p3(3, "Laptop", 800, 50);
	Product p4(4, "computer", 1000, 60);
	Product p5(5, "keyboard", 400, 90);
	Product p6(6, "Mouse", 400, 20);
	arr.insert(p1);
	arr.insert(p2);
	arr.insert(p3);
	arr.insert(p4);
	arr.insert(p5);
	arr.insert(p6);
	int id;
	cout <<endl<< "Enter desired product id: ";
	cin >> id;
	Product p7(id);
	if (arr.search(p7) != -1)
	{
		cout << endl << "Product found at index " << arr.search(p7) << endl;
	}
	else
		cout << endl << "Product not found." << endl;
	int id1;
	cout << endl << "Enter discontinued product id: ";
	cin >> id1;
	Product p8(id1);
	arr.remove(p8);

	if (arr.search(p8) != -1)
	{
		cout << endl << "Product found at index " << arr.search(p8) << endl;
	}
	else
		cout << endl << "Product removed." << endl;
	arr.insert(p3);
	arr.insert(p4);
	arr.insert(p5);
	arr.insert(p6);
	arr.insert(p3);
	arr.insert(p4);
	
}