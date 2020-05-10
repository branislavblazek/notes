#include <iostream>
using namespace std;

struct zviera
{
	int pocet_noh;
};

int main()
{
	int n;
	cout << "Zadajte pocet zvierat: ";
	cin >> n;
	while (cin.get() != '\n');
	
	zviera * zvieratka = new zviera[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Zadajte pocet noh u zvierata c." << i+1 << ": ";
		cin >> zvieratka[i].pocet_noh;
		cin.clear();
		cin.sync();
	}
	
	for (int j = 0; j < n; j++)
	{
		cout << "Adresa je " << &zvieratka[j] << endl;
		cout << "Hodnota je " << zvieratka[j].pocet_noh << endl;
	}
	
	delete [] zvieratka;
	return 0;
}
