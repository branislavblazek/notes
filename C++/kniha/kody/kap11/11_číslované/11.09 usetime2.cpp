// usetime2.cpp - tøetí prográmek na vyzkoušení tøídy Time
// pøeložte spoleènì usetime2.cpp a mytime2.cpp
#include <iostream>
#include "mytime2.h"

int main()
{
	using std::cout;
	using std::endl;
	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;

	cout << "pleni = ";
	weeding.Show();
	cout << endl;

	cout << "vysperkovani = ";
	waxing.Show();
	cout << endl;

	cout << "celkovy cas na zpracovani = ";
	total = weeding + waxing; 	// použit operátor+()
	total.Show();
	cout << endl;

	diff = weeding - waxing; 		// použit operátor-()
	cout << "pleni - sperkovani = ";
	diff.Show();
	cout << endl;

	adjusted = total * 1.5; // použit operátor+()
	cout << "upraveny cas na zpracovani = ";
	adjusted.Show();
	cout << endl;

	return 0;
}
