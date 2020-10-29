// arrayone.cpp -- malá pole celých èísel
#include <iostream>
int main()
{
	using namespace std;
	int yams[3]; 	// vytváøí pole se tøemi prvky
	yams[0] = 7; 	// pøiøazuje hodnotu prvnímu prvku
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = {20, 30, 5}; 	// vytváøí, inicializuje pole
// Poznámka: Jestliže váš pøekladaè nebo pøevodník C++ neumí
// inicializovat toto pole, použijte static int yamcosts[3] namísto
// int yamcosts[3]

	cout << "Celkovy pocet sladkych brambor = ";
	cout << (yams[0] + yams[1] + yams[2]) << "\n";
	cout << "Balicek s " << yams[1] << " sladkymi bramborami stoji ";
	cout << yamcosts[1] << " centu za jeden sladky brambor.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "Celkove vydaje za sladke brambory jsou " << total << " centu.\n";

	cout << "\nVelikost pole yams (sladke brambory) = " << sizeof yams;
	cout << " bajtu.\n";
	cout << "Velikost jednoho prvku = " << sizeof yams[0];
	cout << " bajty.\n";
	return 0;
}
