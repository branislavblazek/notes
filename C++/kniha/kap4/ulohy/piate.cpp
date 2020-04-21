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
	
	Sladkost svacina = {"Mocha Munch", 2.3, 350};
	cout << "Meno: " << svacina.znacka << endl;
	cout << "Vaha: " << svacina.weight << endl;
	cout << "Kalorie: " << svacina.calories << endl;
	
	return 0;
}
