// usebrass1.cpp -- testování tøíd bankovních úètù
// pøekládat s brass.cpp
#include <iostream>
#include "brass.h"

int main()
{
	using std::cout;
	using std::endl;

	Brass Bartas("Jan Bartak", 381299, 4000.00);
	BrassPlus Provaz("Marek Provaznik", 382288, 3000.00);
	Bartas.ViewAcct();
	cout << endl;
	Provaz.ViewAcct();
	cout << endl;
	cout << "Ulozka $1000 na ucet Provaznik:\n";
	Provaz.Deposit(1000.00);
	cout << "Novy zustatek: $" << Provaz.Balance() << endl;
	cout << "Vyber $4200 z uctu Bartak:\n";
	Bartas.Withdraw(4200.00);
	cout << "Zustatek na uctu Bartak: $" << Bartas.Balance() << endl; cout << "Vyber $4200 z uctu Provaznik:\n";
	Provaz.Withdraw(4200.00);
	Provaz.ViewAcct(); 

	return 0;
}
