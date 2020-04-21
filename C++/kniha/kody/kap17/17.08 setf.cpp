// setf.cpp -- øízení formátování pomocí funkce setf()
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	int temperature = 17;

	cout << "Dnesni teplota vody: ";
	cout.setf(ios_base::showpos); // vypíše znaménko plus
	cout << temperature << endl;

	cout << "Pro nase programovaci pratele to je \n";
	cout << std::hex << temperature << endl; // šestnáctkovì
	cout.setf(ios_base::uppercase); // šestnáctkovì velká písmena
	cout.setf(ios_base::showbase); // šestnáctkovì s pøedponou 0X
	cout << "nebo\n";
	cout << temperature << endl;
	cout << "Skutecne " << true << "! vlastne - Skutecne ";
	cout.setf(ios_base::boolalpha);
	cout << true << "!\n";

	return 0;
}
