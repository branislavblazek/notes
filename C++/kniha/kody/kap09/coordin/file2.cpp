// file2.cpp -- obsahuje funkce volané v souboru file1.cpp
#include <iostream>
#include <cmath>
#include "coordin.h" // šablony struktur, prototypy funkcí

// konvertuje pravoúhlé souøadnice na polární
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;

	answer.distance =
		sqrt( xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer; // vrací strukturu polar
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
