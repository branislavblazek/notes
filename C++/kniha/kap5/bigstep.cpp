#include <iostream>
using namespace std;

int main()
{
	cout << "Zadajte cele cislo: ";
	int cislo;
	cin >> cislo;
	for (int i = 0; i <= 1000; i += cislo)
	{
		cout << i << endl;
	}
	cout << "Koniec" << endl;
	return 0;
}
