// strings.cpp -- uklada retezce do pole
#include <iostream>
#include <cstring> 							// pro funkci strlen()
int main()
{
	using namespace std;
	const int Size = 15;
	char name1[Size]; 							// prázdné pole
	char name2[Size] = "C++owboy"; 	// inicializované pole
	// Poznámka: nìkteré implementace mohou vyžadovat
	// pro inicializaci pole name2 klíèové slovo static

	cout << "Ahoj! Jmenuji se " << name2;
	cout << "! Jak se jmenujete vy?\n";
	cin >> name1;
	cout << "Dobre, " << name1 << ", vase jmeno obsahuje ";
	cout << strlen(name1) << " znaku a je ulozeno\n";
	cout << "v poli o velikosti " << sizeof name1 << " bajtu.\n";
	cout << "Pocatecni pismeno vaseho jmena je " << name1[0] << ".\n";
	name2[3] = '\0'; 							// nulový znak
	cout << "Toto jsou prvni tri pismena meho jmena: ";
	cout << name2 << endl;
	
	return 0;
}
