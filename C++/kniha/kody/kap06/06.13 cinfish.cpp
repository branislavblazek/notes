// cinfish.cpp -- nenumerický vstup ukonèuje cyklus
#include <iostream>
const int Max = 5;
int main()
{
	using namespace std;
// získání dat
	double fish[Max];
	cout << "Prosim, zadejte vahy ryb.\n";
	cout << "Muzete zadat az " << Max
			<< " ryb <q pro ukonceni>.\n";
	cout << "ryba c.1: ";
	int i = 0;
	while (i < Max && cin >> fish[i]) {
		if (++i < Max)
			cout << "ryba c." << i+1 << ": ";
	}
// výpoèet prùmìru
	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += fish[j];
// zobrazení výsledkù
	if (i == 0)
		cout << "Nebyla zadana zadna ryba.\n";
	else
		cout << total / i << " = prumerna vaha "
				<< i << " ryb\n";
	cout << "Hotovo.\n";
	
return 0;
}
