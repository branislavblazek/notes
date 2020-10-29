// vegnews.cpp -- použití operátorù new a delete ve tøídách
// compile with strngbad.cpp
#include <iostream>
using std::cout;
#include "strngbad.h"

void callme1(StringBad &); 	// pøedání odkazem
void callme2(StringBad); 		// pøedání hodnotou

int main()
{
	using std::endl;
	StringBad headline1("Celer pochoduje o pulnoci");
	StringBad headline2("Salat se krmi");
	StringBad sports("Spenat opousti misku za dolary");
	cout << "nadpis1: " << headline1 << endl;
	cout << "nadpis2: " << headline2 << endl;
	cout << "sporty: " << sports << endl;
	callme1(headline1);
	cout << "nadpis1: " << headline1 << endl;
	callme2(headline2);
	cout << "nadpis2: " << headline2 << endl;
	cout << "Inicializace jednoho objektu druhým:\n";
	StringBad sailor = sports;
	cout << "namornik: " << sailor << endl;
	cout << "Dosazeni jednoho objektu do druheho:\n";
	StringBad knot;
	knot = headline1;
	cout << "uzel: " << knot << endl;
	cout << "Konec main()\n";

	return 0;
}

void callme1(StringBad & rsb)
{
	cout << "Predani retezce odkazem:\n";
	cout << " \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "Predani retezce hodnotou:\n";
	cout << " \"" << sb << "\"\n";
}
