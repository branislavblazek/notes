// carrots.cpp .. food processing program
// uses and displays a variable

#include <iostream>

int main()
{
	using namespace std;

	int carrots; 						// deklarace celoèíselné promìnné

	carrots = 25; 						// pøiøazení hodnoty promìnné
	cout << "Mam ";
	cout << carrots; 				// výpis hodnoty promìnné
	cout << " mrkvi.";
	cout << endl;
	carrots = carrots - 1; 		// modifikace promìnné
	cout << "Krup, krup. Ted mam " << carrots << " mrkvi." << endl;

	return 0;
}
