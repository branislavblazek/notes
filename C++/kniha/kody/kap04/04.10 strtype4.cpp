// strtype4.cpp -- radkovy vstup
#include <iostream>
#include <string> 					// zpøístupnìní tøídy string
#include <cstring> 				// knihovna øetìzcù v C
int main()
{
	using namespace std;
	char charr[20];
	string str;

	cout << "Delka retezce v charr pred vstupem: "
			<< strlen(charr) << endl;
	cout << "Delka retezce v str pred vstupem: "
			<< str.size() << endl;
	cout << "Zadejte textovy radek:\n";
	cin.getline(charr, 20); 		// indikace maximální délky
	cout << "Zadali jste: " << charr << endl;
	cout << "Zadejte dalsi radek:\n";
	getline(cin, str); 				// cin je nyní argumentem; délka není uvedena
	cout << "Zadali jste: " << str << endl;
	cout << "Delka retezce v charr po vstupu je: "
			<< strlen(charr) << endl;
	cout << "Delka retezce v str po vstupu je: "
			<< str.size() << endl;

	return 0;
}
