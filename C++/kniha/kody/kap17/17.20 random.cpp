// random.cpp -- pøímý pøístup k binárnímu souboru
#include <iostream> // vìtšina systémù nepožaduje
#include <fstream>
#include <iomanip>
#include <cstdlib> // nebo stdlib.h kvùli funkci exit()
const int LIM = 20;
struct planet
{
	char name[20]; // název planety
	double population; // poèet obyvatel
	double g; // tíhové zrychlení
};

const char * file = "planets.dat"; // pøedpokládá existenci (pøíklad binary.cpp)
inline void eatline() { while (std::cin.get() != '\n') continue; }

int main()
{
	using namespace std;
	planet pl;
	cout << fixed;

// zobrazení poèáteèního obsahu
	fstream finout; // toky pro ètení a zápis
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	// Poznámka: V nìkterých systémech Unix je nutné vynechat | ios::binary
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0); // jdi na zaèátek
		cout << "Soucasny obsah souboru "
				<< file << ":\n";
		while (finout.read((char *) &pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": "
					<< setprecision(0) << setw(12) << pl.population
					<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
			finout.clear(); // vynuluje pøíznak konce souboru eof
		else
		{
			cerr << "Chyba pri cteni souboru " << file << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "Soubor " << file << " se nepodarilo otevrit -- nazdar.\n";
		exit(EXIT_FAILURE);
	}

// zmìna záznamu
	cout << "Zadejte cislo zaznamu, ktery chcete zmenit: ";
	long rec;
	cin >> rec;
	eatline(); // zbaví se znaku nového øádku
	if (rec < 0 || rec >= ct)
	{
		cerr << "Neplatne cislo zaznamu -- nazdar\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl; // konverze na typ streampos
	finout.seekg(place); // pøímý pøístup
	if (finout.fail())
	{
		cerr << "Chyba pri hledani zaznamu\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char *) &pl, sizeof pl);
	cout << "Pozadovany zaznam:\n";
	cout << rec << ": " << setw(LIM) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
		finout.clear(); // vynuluje pøíznak konce souboru eof
	cout << "Zadejte nazev planety: ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "Zadejte pocet obyvatel planety: ";
	cin >> pl.population;
	cout << "Zadejte tihove zrychleni planety: ";
	cin >> pl.g;
	finout.seekp(place); // návrat
	finout.write((char *) &pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "Chyba pri zapisu\n";
		exit(EXIT_FAILURE);
	}

// zobrazení aktualizovaného souboru
	ct = 0;
	finout.seekg(0); // jdi na zaèátek souboru
	cout << "Novy obsah souboru " << file << ":\n"
			<< " file:\n";
	while (finout.read((char *) &pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(LIM) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "Hotovo.\n";
	
	return 0;
}
