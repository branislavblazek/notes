// precise.cpp -- nastavení pøesnosti, zobrazení desetinné teèky
#include <iostream>

int main()
{
	using std::cout;
	using std::ios_base;
	
    float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;

	cout.setf(ios_base::showpoint);
	cout << "\"Furry Friends\" stoji $" << price1 << "!\n";
	cout << "\"Fiery Fiends\" stoji $" << price2 << "!\n";

	cout.precision(2);
	cout << "\"Furry Friends\" stoji $" << price1 << "!\n";
	cout << "\"Fiery Fiends\" stoji $" << price2 << "!\n";

	return 0;
}
