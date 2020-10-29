// precise.cpp -- nastavení pøesnosti
#include <iostream>

int main()
{
	using std::cout;
	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;

	cout << "\"Furry Friends\" stoji $" << price1 << "!\n";
	cout << "\"Fiery Fiends\" stoji $" << price2 << "!\n";

	cout.precision(2);
	cout << "\"Furry Friends\" stoji $" << price1 << "!\n";
	cout << "\"Fiery Fiends\" stoji $" << price2 << "!\n";

	return 0;
}
