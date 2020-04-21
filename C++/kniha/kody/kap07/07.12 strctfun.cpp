// strctfun.cpp -- funkce s parametrem typu struktura
#include <iostream>
#include <cmath>

// šablony struktur
struct polar
{
	double distance; 		// vzdálenost od poèátku
	double angle; 				// smìr od poèátku
};
struct rect
{
	double x; 					// horizontální vzdálenost od poèátku
	double y; 					// vertikální vzdálenost od poèátku
};

// prototypy
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;

	cout << "Zadejte hodnoty x a y: ";
	while (cin >> rplace.x >> rplace.y) 	// úhledné použití cin
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Dalsi dve cisla (q na ukoceni): ";
	}
	cout << "Hotovo!\n";
	return 0;
}

// konvertuje pravoúhlé souøadnice na polární
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;

	answer.distance =
		sqrt( xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer; 		// vrací strukturu polar
}

// zobrazení polárních souøadnic spolu s konverzí úhlu na stupnì
void show_polar (polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;

	cout << "vzdalenost = " << dapos.distance;
	cout << ", uhel = " << dapos.angle * Rad_to_deg;
	cout << " stupnu\n";
}
