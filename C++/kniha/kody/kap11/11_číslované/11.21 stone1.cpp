// stone1.cpp -- uživatelem definované konverzní funkce
// pøeložit se souborem stonewt1.cpp
#include <iostream>
#include "stonewt1.h"

int main()
{
	using std::cout;
	Stonewt poppins(9, 2.8); // 9 kamenù, 2.8 liber
	double p_wt = poppins; // implicitní konverze
	cout << "Konverze na typ double => ";
	cout << "Poppins: " << p_wt << " liber.\n";
	cout << "Konverze na typ int => ";
	cout << "Poppins: " << int (poppins) << " liber.\n";
	return 0;
}
