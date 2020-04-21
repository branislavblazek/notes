// morechar.cpp - typy char versus int
#include <iostream>
int main()
{
	using namespace std;
	char ch = 'M'; 			// pøiøaï ASCII kód M do ch
	int i = ch; 				// pøiøaï tentýž kód do int
	cout << "The ASCII code for " << ch << " is " << i << endl;

	cout << "Ke kodu znaku prictu jednicku:" << endl;
	ch = ch + 1; 				// zmìò kód znaku v c
	i = ch; 						// nový znak ulož do i
	cout << "ASCII kod znaku " << ch << " je " << i << endl;

	// pouziti clenske funkce cout.put() k vypisu znaku
	cout << "Znak ch vypisuji pomoci cout.put(ch): ";
	cout.put(ch);

	// pouziti cout.put() k vypisu znakove konstanty
	cout.put('!');
	cout << endl << "Hotovo" << endl;
	return 0;
}
