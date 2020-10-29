// addpntrs.cpp -- pøièítání k ukazatelùm
#include <iostream>
int main()
{
	using namespace std;
	double wages[3] = {10000.0, 20000.0, 30000.0};
	short stacks[3] = {3, 2, 1};

// Zde jsou dva zpùsoby získání adresy pole
	double * pw = wages; // jméno pole = adresa
	short * ps = &stacks[0]; // nebo použití adresového operátoru
// s prvkem pole
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "k ukazateli pw pricteme 1:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "k ukazateli ps pricteme 1:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	cout << " zpristupneni dvou prvku pomoci zapisu pole \n";
	cout << "stacks[0] = " << stacks[0]
			<< ", stacks[1] = " << stacks[1] << endl;
	cout << " zpristupneni dvou prvku pomoci zapisu ukazatele \n";
	cout << "*stacks = " << *stacks
			<< ", *(stacks + 1) = " << *(stacks + 1) << endl;

	cout << sizeof wages << " = velikost pole wages\n";
	cout << sizeof pw << " = velikost ukazatele pw\n";
	
	return 0;
}
