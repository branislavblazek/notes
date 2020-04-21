// sumafile.cpp -- funkce s argumentem typu pole
#include <iostream>
#include <fstream> 				// podpora souborových V/V operací
#include <cstdlib> 				// podpora objektu exit()
const int SIZE = 60;
int main()
{
	using namespace std;
	char filename[SIZE];
	ifstream inFile; 				// objekt pro zpracování vstupu ze souboru

	cout << "Zadejte jmeno datoveho souboru: ";
	cin.getline(filename, SIZE);
	inFile.open(filename); 		// pøiøazení inFile k souboru
	if (!inFile.is_open()) 		// nepodaøilo se otevøít
	{
		cout << "Nepodarilo se otevrit soubor " << filename << endl;
		cout << "Program se ukonci.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0; 					// poèet pøeètených položek

	inFile >> value; 				// èti první hodnotu
	while (inFile.good()) 		// dokud je vstup v poøádku a není EOF
	{
		++count; 							// èti další položku
		sum += value; 					// vypoèti celkový souèet
		inFile >> value; 			// èti další hodnotu
	}
	if (inFile.eof())
		cout << "Konec souboru.\n";
	else if (inFile.fail())
		cout << "Cteni se ukoncilo, nespravna data.\n";
	else
		cout << "Cteni se ukoncilo z neznameho duvodu.\n";
	if (count == 0)
		cout << "Nezpracovala se zadna data.\n";
	else
	{
		cout << "Pocet prectenych polozek: " << count << endl;
		cout << "Soucet: " << sum << endl;
		cout << "Prumer: " << sum / count << endl;
	}
	inFile.close(); 			// zavri soubor
	
	return 0;
}
