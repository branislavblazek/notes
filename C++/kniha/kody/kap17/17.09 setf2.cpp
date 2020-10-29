// setf2.cpp -- øízení formátování pomocí funkce setf() se dvìma parametry
#include <iostream>
#include <cmath>

int main()
{
	using namespace std;
	// zarovnání vlevo, zobrazení znaménka plus, zobrazení koncových
	// nul, pøesnost na 3 místa
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);
	// e-notace a uložení pùvodního nastavení formátování
	ios_base::fmtflags old = cout.setf(ios_base::scientific,
		ios_base::floatfield);
	cout << "Zarovnani vlevo:\n";
	long n;
	for (n = 1; n <= 41; n+= 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
}

	// zmìna na vnitøní zarovnání
	cout.setf(ios_base::internal, ios_base::adjustfield);
	// obnovení implicitního stylu zobrazení typu float
	cout.setf(old, ios_base::floatfield);

	cout << "Vnitrni zarovnani:\n";
	for (n = 1; n <= 41; n+= 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	// zarovnání vpravo, zápis s pevným oddìlovaèem
	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Zarovnani vpravo:\n";
	for (n = 1; n <= 41; n+= 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	return 0;
}
