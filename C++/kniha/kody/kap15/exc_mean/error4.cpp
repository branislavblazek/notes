//error4.cpp -- použití tøídy výjimek
#include <iostream>
#include <cmath> // nebo math.h, v Unixu možná -lm
#include "exc_mean.h"
// function prototypes
double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Zadejte dve cisla: ";
	while (cin >> x >> y)
	{
		try { 												// zaèátek bloku try
			z = hmean(x,y);
			cout << "Harmonicky prumer cisel " << x << " a " << y
					<< " je " << z << endl;
			cout << "Geometricky prumer cisel " << x << " a " << y
					<< " je " << gmean(x,y) << endl;
			cout << "Zadejte dalsi mnozinu cisel <k pro ukonceni>: ";
		} 															// konec bloku try
		catch (bad_hmean & bg) // zaèátek záchytného bloku
		{
			bg.mesg();
			cout << "Opakujte.\n";
			continue;
		}
		catch (bad_gmean & hg)
		{
			cout << hg.mesg();
			cout << "Použité hodnoty: " << hg.v1 << ", "
					<< hg.v2 << endl;
			cout << "Bohuzel, dal se nedostanete. ";
			break;
		} // konec záchytného bloku
	}
	cout << "Nashledanou!\n";
	return 0;
}

double hmean(double a, double b) throw(bad_hmean)
{
	if (a == -b)
		throw bad_hmean(a,b);
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) throw(bad_gmean)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a,b);
	return std::sqrt(a * b);
}
