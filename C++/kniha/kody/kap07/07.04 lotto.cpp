// lotto.cpp - pravdìpodobnost výhry
#include <iostream>
// Poznámka: nìkteré implementace vyžadují double místo long double
long double probability(unsigned numbers, unsigned picks);
int main()
{
	using namespace std;
	double total, choices;
	cout << 	"Zadejte celkovy pocet cisel na sazence\n"
					"a pocet moznych voleb:\n";
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "Mate pravdepodobnost jedna ku ";
		cout << probability(total, choices); 			// výpoèet pravdìpodobnosti
		cout << ", ze vyhrajete.\n";
		cout << "Dalsi dve cisla (q pro ukonceni): ";
	}
	cout << "Sbohem\n";
	return 0;
}
// následující funkce poèítá pravdìpodobnost výbìru
// správných èísel z celkového poètu možností
long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0; // zde je nìkolik lokálních promìnných
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p ;
	return result;
}
