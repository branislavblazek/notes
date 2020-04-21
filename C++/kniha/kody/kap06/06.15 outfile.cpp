// outfile.cpp -- writing to a file
#include <iostream>
#include <fstream> 				// souborové V/V operace

int main()
{
	using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile; 					// vytvoø objekt pro výstup
	outFile.open("carinfo.txt"); 		// pøiøaï jej k souboru

	cout << "Zadejte vyrobce a model automobilu: ";
	cin.getline(automobile, 50);
	cout << "Zadejte rok vyroby: ";
	cin >> year;
	cout << "Zadejte puvodni pozadovanou cenu: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

// pomocí cout vypiš data na displeji

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Vyrobce a model: " << automobile << endl;
	cout << "Rok: " << year << endl;
	cout << "Puvodni cena $" << a_price << endl;
	cout << "Nynejsi cena $" << d_price << endl;

// nyni totez s pouzitim outFile

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Vyrobce a model: " << automobile << endl;
	outFile << "Rok: " << year << endl;
	outFile << "Puvodni cena Kc: " << a_price << endl;
	outFile << "Soucasna cena Kc: " << d_price << endl;
	outFile.close(); 				// zavri soubor
	
	return 0;
}
