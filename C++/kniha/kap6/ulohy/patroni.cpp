#include <iostream>
using namespace std;

struct patron
{
	char meno[100];
	double ciastka;	
};

int main()
{
	int n;
	cout << "Zadajte pocet darcov: ";
	cin >> n;
	
	cin.clear();
	cin.sync();
	
	patron * darcovia = new patron[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Zadajte meno " << i+1 << ". darca: " << endl;
		cin.getline(darcovia[i].meno, 100);
		cout << "Zadajte jeho ciastku: ";
		cin >> darcovia[i].ciastka;
		while (cin.get() != '\n');
	}
	
	cout << "Adresa pola je " << &darcovia[0] << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << "Adresa tohoto je " << &darcovia[i] << endl;
		cout << darcovia[i].meno << endl;
		cout << darcovia[i].ciastka << endl;
	}
	
	delete [] darcovia;
	return 0;
}
