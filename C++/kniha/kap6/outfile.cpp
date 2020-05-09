#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;
	
	ofstream outFile;
	outFile.open("carinfo.txt");
	
	cout << "Zadajte meno vyrobca auta: ";
	cin.getline(automobile, 50);
	cout << "Zadajte rok vyroby: ";
	cin >> year;
	cout << "Zadate povodnu pozadovanu cenu: ";
	cin >> a_price;
	d_price = 0.987 * a_price;
	
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Vyrobca a model: " << automobile << endl;
	cout << "Rok: " << year << endl;
	cout << "Povodna cena $: " << a_price << endl;
	cout << "Terajsia cena $: " << d_price << endl;
	
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Vyrobca a model: " << automobile << endl;
	outFile << "Rok: " << year << endl;
	outFile << "Povodna cena $: " << a_price << endl;
	outFile << "Terajsia cena $: " << d_price << endl;
	outFile.close();
	return 0;
	
}
