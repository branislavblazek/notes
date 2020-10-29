// usett1.cpp -- použití základní a odvozené tøídy
#include <iostream>
#include "tabtenn1.h"

int main ( void )
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Katerina", "Kepakova", false);
	RatedPlayer rplayer1(1140, "Pepa", "Prerovsky", true);
	rplayer1.Name(); // derived object uses base method
	if (rplayer1.HasTable())
		cout << ": ma stul.\n";
	else
		cout << ": nema stul.\n";
	player1.Name(); // base object uses base method
	if (player1.HasTable())
		cout << ": ma stul";
	else
		cout << ": nema stul.\n";
	cout << "Jmeno: ";
	rplayer1.Name();
	cout << "; Hodnoceni: " << rplayer1.Rating() << endl;
	RatedPlayer rplayer2(1212, player1);
	cout << "Jmeno: ";
	rplayer2.Name();
	cout << "; Hodnoceni: " << rplayer2.Rating() << endl;

	return 0;
}
