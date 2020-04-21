// pointer.cpp -- naše první ukazatelová promìnná
#include <iostream>
int main()
{
	using namespace std;
	int updates = 6; 			// deklaruje promìnnou
	int * p_updates; 			// deklaruje ukazatel na int

	p_updates = &updates; 	// pøiøazuje adresu int ukazateli

// vyjadøuje hodnoty dvìma zpùsoby
	cout << "Hodnoty: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;

// vyjadøuje hodnoty dvìma zpùsoby
	cout << "Adresy: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;

// používá ukazatel na zmìnu hodnoty
	*p_updates = *p_updates + 1;
	cout << "Promenna updates nyni = " << updates << endl;
	
	return 0;
}
