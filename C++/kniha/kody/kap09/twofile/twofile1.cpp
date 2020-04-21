// twofile1.cpp -- promìnné s vnìjší a vnitøní vazbou
#include <iostream> // bude pøekládán se souborem twofile2.cpp
int tom = 3; // definice vnìjší promìnné
int dick = 30; // definice vnìjší promìnné
static int harry = 300; // statická promìnná, vnitøní vazba

// prototyp funkce
void remote_access();

int main()
{
	using namespace std;
	cout << "main() podava zpravu o nasledujicich adresach:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
	remote_access();
	
	return 0;
}
