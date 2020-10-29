// usett0.cpp -- pouití základní tøídy
#include <iostream>
#include "tabtenn0.h"

int main ( void )
{
	using std::cout;
	TableTennisPlayer player1("Mojmir", "Kopriva", true);
	TableTennisPlayer player2("Katerina", "Kepakova", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": ma stul.\n";
	else
		cout << ": nema stul.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": ma stul";
	else
		cout << ": nema stul.\n";

	return 0;
}
