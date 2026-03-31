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
	void show(int index)
	{
		cout<< arr[index];
	}
};
class Word
{
	string word;
	string definition;
	string partofspeach;
public:
	Word(string w, string d, string p)
	{
		word = w;
		definition = d;
		partofspeach = p;
	}
	Word()
	{
		word = "";
	}
	Word(string w)
	{
		word = w;
	}
	void display()
	{
		cout << endl << word << "\t" << definition << "\t" << partofspeach << endl;
	}
	bool operator==(Word& obj)
	{
		return (word == obj.word);
	}
	friend ostream& operator<<(ostream& out, Word obj);
};
ostream& operator<<(ostream& out, Word obj)
{
	out << obj.word << "\t" << obj.definition << "\t" << obj.partofspeach << endl;
	return out;
}

int main()
{
	Array <Word> arr(5);
	string w, d, p;
	Word ab[5];
	for (int i = 0;i < 5;)
	{

		cout << i + 1 << ": " << endl;
		cout << "Enter word: ";
		cin >> w;
		cout << "Enter word definition: ";
		cin >> d;
		cout << "Enter the part of speach: ";
		cin >> p;
		ab[i] = Word(w, d, p);

		if (arr.search(ab[i]) == -1)
		{
			arr.insert(ab[i]);
		i++;
	    }
		else
			cout << "Word already exists."<<endl;
	}
	string w1;
	cout << "Enter the word word you want to remove: ";
	cin >> w1;
	Word w2(w1);
	arr.remove(w1);
	cout << "Enter the word you want to find: ";
	cin >> w1;
	int index = arr.search(w1);
	if (index != -1)
		arr.show(index);
	else
		cout << endl << "Word not found" << endl;
	
	Word w4("word", "definition", "nown");
	arr.insert(w);
	arr.insert(w);
	return 0;
}