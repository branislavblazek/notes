// binary.cpp - V/V operace v binárním souboru
#include <iostream> // vìtšina systémù nepožaduje
#include <fstream>
#include <iomanip>
#include <cstdlib> // (nebo stdlib.h) kvùli funkci exit()

inline void eatline() { while (std::cin.get() != '\n') continue; }
struct planet
{
	char name[20]; // název planety
	double population; // poèet obyvatel
	double g; // tíhové zrychlení
};

const char * file = "planets.dat";

int main()
{
	using namespace std;
	planet pl;
	cout << fixed << right;

// výpis pùvodního obsahu
	ifstream fin;
	fin.open(file, ios_base::in |ios_base::binary); // binární soubor
	// Poznámka: nìkteré systémy neakceptují režim ios_base::binary
	if (fin.is_open())
	{
	cout << "Soucasny obsah souboru "
			<< file << ":\n";
	while (fin.read((char *) &pl, sizeof pl))
	{
		cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
	}
	fin.close();
	}

// pøidání nových údajù
	ofstream fout(file,
				ios_base::out | ios_base::app | ios_base::binary);
	//Poznámka: nìkteré systémy neakceptují režim ios::binary
	if (!fout.is_open())
	{
		cerr << "Soubor " << file << " nelze otevrit pro vystup:\n";
		exit(EXIT_FAILURE);
	}

	cout << "Zadejte nazev planety (prazdny radek pro ukonceni):\n";
	cin.get(pl.name, 20);
	while (pl.name[0] != '\0')
	{
		eatline();
		cout << "Zadejte pocet obyvatel planety: ";
		cin >> pl.population;
		cout << "Zadejte tihove zrychleni planety: ";
		cin >> pl.g;
		eatline();
		fout.write((char *) &pl, sizeof pl);
		cout << "Zadejte nazev planety (prazdny radek pro ukonceni):\n";
		cin.get(pl.name, 20);
	}
	fout.close();

// zobrazení aktualizovaného souboru
	fin.clear(); // nìkteré implementace nevyžadují, ale neuškodí
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Novy obsah souboru "
				<< file << ":\n";
		while (fin.read((char *) &pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "
					<< setprecision(0) << setw(12) << pl.population
					<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	cout << "Hotovo.\n";

	return 0;
}
