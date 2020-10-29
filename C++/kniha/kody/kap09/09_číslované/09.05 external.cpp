// external.cpp -- vnìjší (externí) promìnné
#include <iostream>
using namespace std;
// vnìjší promìnná
double otepleni = 0.3;

// funkèní prototypy
void update(double dt);
void local();

int main() 				// používá globální promìnnou
{
	cout << "Globalni promenna otepleni je " << otepleni << " stupnu.\n";
	update(0.1); 		// vyvolání funkce na zmìnu promìnné otepleni
	cout << "Globalni promenna otepleni je " << otepleni << " stupnu.\n";
	local(); 				// vyvolání funkce na lokální promìnnou otepleni
	cout << "Globalni promenna otepleni je " << otepleni << " stupnu.\n";
	
	return 0;
}

void update(double dt) 		// modifikuje globální promìnnou
{
	extern double otepleni; // volitelná opìtná deklarace
	otepleni += dt;
	cout << "Zmena globalni promenne otepleni na " << otepleni;
	cout << " stupnu.\n";
}

void local() // používá lokální promìnnou
{
	double otepleni = 0.8; // nová promìnná skrývá vnìjší promìnnou

	cout << "Lokalni promenna otepleni = " << otepleni << " stupnu.\n";
			// Pøístup ke globální promìnné pomocí
			// operátoru na rozlišení platnosti
	cout << "Ale globalni promenna otepleni = " << ::otepleni;
	cout << " stupnu.\n";
}
