// coordin.h -- šablony struktur a prototypy funkcí
// šablony struktur
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
	double distance; 	// vzdálenost od poèátku
	double angle; 			// smìr od poèátku
};
struct rect
{
	double x; 	// horizontální vzdálenost od poèátku
	double y; 	// vertikální vzdálenost od poèátku
};

// prototypy
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
#endif
