#include<iostream>
#include"header.h"
using namespace std;
int main()
{
	Leaderboard <int> l1("Haseeb", 98);
	l1.addplayer("Unknown", 23);
	l1.addplayer("Known", 99);
	Leaderboard <double> l2("Haseeb", 3.56);
	l2.addplayer("Unknown", 3.43);
	l2.addplayer("Known", 3.37);
	cout << "By score: " << endl;
	l1.show();
	l1.winner();
	cout << endl <<endl<< "By GPA:  " << endl;
	l2.show();
	l2.winner();
}
