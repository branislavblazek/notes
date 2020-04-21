// strctptr.cpp -- funkce s parametry typu ukazatel na strukturu
#include <iostream>
#include <cmath>

// šablony struktur
struct polar
{
	double distance; 	// vzdálenost od poèátku
	double angle; 			// smìr od poèátku
};
struct rect
{
	double x; 				// horizontální vzdálenost od poèátku
	double y; 				// vertikální vzdálenost od poèátku
};

// prototypy
void rect_to_polar(const rect * pxy, polar * pda);
void show_polar (const polar * pda);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;

	cout << "Zadejte hodnoty x a y: ";
	while (cin >> rplace.x >> rplace.y)
	{
		rect_to_polar(&rplace, &pplace); 		// pøedání adresy
		show_polar(&pplace); 							// pøedání adresy
		cout << "Dalsi dve cisla (q na ukonceni): ";
	}
	cout << "Hotovo!\n";
	return 0;
}

// zobrazení polárních souøadnic spolu s konverzí úhlu na stupnì
void show_polar (const polar * pda)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;

	cout << "vzdalenost = " << pda->distance;
	cout << ", uhel = " << pda->angle * Rad_to_deg;
	cout << " stupnu\n";
}

// konvertuje pravoúhlé souøadnice na polární
void rect_to_polar(const rect * pxy, polar * pda)
{
	using namespace std;
	pda->distance =
		sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}
