// fileio.cpp -- uložení do souboru
#include <iostream> // pouze v nìkterých systémech
#include <fstream>
#include <string>

int main()
{
	using namespace std;
	string filename;

	cout << "Zadejte nazev noveho souboru: ";
	cin >> filename;

// vytvoøení objektu výstupního toku pro nový soubor s názvem fout
	ofstream fout(filename.c_str());

	fout << "Prisne tajne!\n"; 	// zapisuje do souboru
	cout << "Zadejte vase tajne cislo: "; // zapisuje na obrazovku
	float secret;
	cin >> secret;
	fout << " Vase tajne cislo je " << secret << endl;
	fout.close(); 							// uzavøe soubor

// vytvoøení objektu vstupního toku pro nový soubor s názvem fin
	ifstream fin(filename.c_str());
	cout << "Zde je obsah souboru " << filename << ":\n";
	char ch;
	while (fin.get(ch)) 				// ète znak ze souboru
		cout << ch; 						// a zapisuje ho na obrazovku
	cout << "Konec\n";
	fin.close();

	return 0;
}
