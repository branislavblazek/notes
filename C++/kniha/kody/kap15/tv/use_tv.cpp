//use_tv.cpp -- použití tøíd Tv a Remote
#include <iostream>
#include "tv.h"

int main()
{
	using std::cout;
	Tv s27;
	cout << "Pocatecni nastaveni 27\" televize:\n";
	s27.settings();
	s27.onoff();
	s27.chanup();
	cout << "\nUpravene nastaveni 27\" televize:\n";
	s27.settings();

	Remote grey;

	grey.set_chan(s27, 10);
	grey.volup(s27);
	grey.volup(s27);
	cout << "\n27\" nastaveni pro pouziti dalkoveho ovladace:\n";
	s27.settings();

	Tv s32(Tv::On);
	s32.set_mode();
	grey.set_chan(s32,28);
	cout << "\n27\" nastaveni:\n";
	s32.settings();

	return 0;
}
