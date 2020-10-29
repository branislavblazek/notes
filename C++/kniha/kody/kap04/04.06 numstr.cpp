// numstr.cpp -- øádkovı vstup následující vstup èísla
#include <iostream>
int main()
{
	using namespace std;
	cout << "V kterem roce byl vas dum postaven?\n";
	int year;
	cin >> year;
	cout << "Jaka je jeho adresa?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Rok vystavby: " << year << endl;
	cout << "Adresa: " << address << endl;
	cout << "Konec!\n";
	
	return 0;
}
