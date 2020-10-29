// stone.cpp - uživatelem definované konverze
// pøeložit se souborem stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt & st, int n);
int main()
{
	Stonewt pavarotti = 260; 	// použití konstruktoru k inicializaci
	Stonewt wolfe(285.7); 		// stejné jako Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);

	cout << "Tenor vazil ";
	pavarotti.show_stn();
	cout << "Detektiv vazil ";
	wolfe.show_stn();
	cout << "Prezident vazil ";
	taft.show_lbs();
	pavarotti = 265.8; 			// použití konstruktoru ke konverzi
	taft = 325; 						// stejné jako taft = Stonewt(325);
	cout << "Po veceri tenor vazil ";
	pavarotti.show_stn();
	cout << "Po veceri prezident vazil ";
	taft.show_lbs();
	display(taft, 2);
	cout << "Zapasnik vazil jeste vic.\n";
	display(422, 2);
	cout << "Zadny kamen nezbyl \n";
	return 0;
}

void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Uf! ";
		st.show_stn();
	}
}
