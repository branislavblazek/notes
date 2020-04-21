// file1.cpp -- pøíklad dvousouborového programu
#include <iostream>
#include "coordin.h" // šablony struktur, prototypy funkcí
using namespace std;
int main()
{
	rect rplace;
	polar pplace;

	cout << "Zadejte hodnoty x a y: ";
	while (cin >> rplace.x >> rplace.y) 	// úhledné použití cin
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Dalsi dve cisla (q pro ukonceni): ";
	}
	cout << "Hotovo!\n";
	return 0;
}
