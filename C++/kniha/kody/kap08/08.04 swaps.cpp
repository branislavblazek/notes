// swaps.cpp -- zámìna pomocí odkazù a ukazatelù
#include <iostream>
void swapr(int & a, int & b); 	// a, b jsou jiná jména promìnných typu int
void swapp(int * p, int * q); 	// p, q jsou adresy promìnných typu int
void swapv(int a, int b); 		// a, b jsou nové promìnné
int main()
{
	using namespace std;
	int wallet1 = 300;
	int wallet2 = 350;

	cout << "penezenka1 = Kc " << wallet1;
	cout << " penezenka2 = Kc " << wallet2 << endl;

	cout << "Pouziti odkazu na zamenu obsahu:\n";
	swapr(wallet1, wallet2); 						// pøedání promìnných
	cout << "penezenka1 = Kc " << wallet1;
	cout << " penezenka2 = Kc " << wallet2 << endl;

	cout << "Pouziti ukazatelu na zamenu obsahu:\n";
	swapp(&wallet1, &wallet2); 					// pøedání adres promìnných
	cout << "penezenka1 = Kc " << wallet1;
	cout << " penezenka2 = Kc " << wallet2 << endl;

	cout << "Pokus pouziti predani hodnotou:\n";
	swapv(wallet1, wallet2); 						// pøedání hodnot promìnných
	cout << "penezenka1 = Kc " << wallet1;
	cout << " penezenka2 = Kc " << wallet2 << endl;
	return 0;
}

void swapr(int & a, int & b) 	// použití odkazù
{
	int temp;

	temp = a; 								// použití a, b pro hodnoty promìnných
	a = b;
	b = temp;
}

void swapp(int * p, int * q) 	// použití ukazatelù
{
	int temp;

	temp = *p; 								// použití *p, *q pro hodnoty promìnných
	*p = *q;
	*q = temp;
}

void swapv(int a, int b) 			// zkouška použití hodnot
{
	int temp;

	temp = a; 								// použití a, b pro hodnoty promìnných
	a = b;
	b = temp;
}

