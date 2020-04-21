 // usestok1.cpp -- použití tøídy Stock
#include <iostream>
#include "stock1.h"

int main()
{
	using std::cout;
	using std::ios_base;
	cout.precision(2); 														// #.## formát
	cout.setf(ios_base::fixed, ios_base::floatfield);		// #.## formát
	cout.setf(ios_base::showpoint); 									// #.## formát

	cout << "Vytvoreni novych objektu pomoci konstruktoru\n";
	Stock stock1("NanoSmart", 12, 20.0); // syntax 1
	stock1.show();
	Stock stock2 = Stock ("Boffo Objects", 2, 2.0); 		// syntaxe 2
	stock2.show();

	cout << "Dosazeni stock1 do stock2:\n";
	stock2 = stock1;
	cout << "Vypis stock1 a stock2:\n";
	stock1.show();
	stock2.show();

	cout << "Obnova objektu pomoci konstruktoru \n";
	stock1 = Stock("Nifty Foods", 10, 50.0); 					// doèasný objekt
	cout << "Obnoveny stock1:\n";
	stock1.show();
	cout << "Hotovo\n";
	return 0;
}
