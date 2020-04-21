// twofile2.cpp -- promìnné s vnitøní a vnìjší vazbou
#include <iostream>
extern int tom; // promìnná tom definovaná jinde
static int dick = 10; // pøekrývá vnìjší promìnnou dick
int harry = 200; // definice vnìjší promìnné,
// bez konfliktu s promìnnou harry v twofile1

void remote_access()
{
	using namespace std;
	cout << "remote_access() podava zpravu o nasledujicich adresach:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
}
