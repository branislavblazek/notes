// cingolf.cpp -- pøeskoèení nenumerického vstupu
#include <iostream>
const int Max = 5;
int main()
{
	using namespace std;
// získání dat
	int golf[Max];
	cout << "Prosim, zadejte skore v golfu.\n";
	cout << "Musite zadat " << Max << " her.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "hra c." << i+1 << ": ";
		while (!(cin >> golf[i])) {
			cin.clear(); // obnovení vstupu
			while (cin.get() != '\n')
				continue; // zahození chybných vstupních dat
			cout << "Prosim, zadejte cislo: ";
		}
	}
// výpoèet prùmìru
	double total = 0.0;
	for (i = 0; i < Max; i++)
	total += golf[i];
// zobrazení výsledkù
	cout << total / Max << " = prumerne skore za "
			<< Max << " her\n";
	
	return 0;
}
