#include <iostream>
using namespace std;

int main()
{
	struct Sladkost
	{
		char znacka[40];
		double weight;
		int calories;
	};
	
	Sladkost svacina[3] = {
		{"Mocha Munch", 2.3, 350},
		{"Horalka", 4, 300},
		{"Mila", 2.6, 321}
	};
	cout << "Meno: " << svacina[0].znacka << endl;
	cout << "Meno: " << svacina[1].znacka << endl;
	cout << "Meno: " << svacina[2].znacka << endl;
	
	return 0;
}
