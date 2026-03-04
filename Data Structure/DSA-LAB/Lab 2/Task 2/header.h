#pragma once
#include<iostream>
#include<string>
using namespace std;
template <typename T>
class Leaderboard
{
	string name[100];
	T score[100];
	int count = 0;
public:
	Leaderboard(string n, T s)
	{
		name[count] = n;
		score[count] = s;
		count++;
	}
	void addplayer(string n, T s)
	{
		if (count <= 100)
		{
			name[count] = n;
			score[count] = s;
			count++;
		}
		else
		{
			cout << "Limit reached." << endl;;
		}
	}
	void show()
	{
		cout <<endl<< "Player     Score" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << name[i] << "    " << score[i]<<endl;
		}
	}
	void winner()
	{
		T max = 0;
		int index;
		for (int i = 0; i < count; i++)
		{
			if (score[i] > max)
			{
				max = score[i];
				index = i;
			}

		}
		cout << "Winner: " << endl;
		cout<< name[index] << "    " << score[index];
	}
	};
