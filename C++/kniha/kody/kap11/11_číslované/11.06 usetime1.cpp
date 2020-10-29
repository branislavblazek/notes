// usetime1.cpp -- použití druhého návrhu tøídy Time
// pøekládat se soubory usetime1.cpp a mytime1.cpp 
#include <iostream>
#include "mytime1.h"
int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planovani = ";
	planning.Show();
	cout << endl;

	cout << "programovani = ";
	coding.Show();
	cout << endl;

	cout << "ladeni = ";
	fixing.Show();
	cout << endl;

	total = coding + fixing;
	// zápis operátoru
	cout << "programovani + ladeni = ";
	total.Show();
	cout << endl;

	Time morefixing(3, 28);
	cout << "dalsi ladeni = ";
	morefixing.Show();
	cout << endl;
	total = morefixing.operator+(total);
	// zápis funkce
	cout << "morefixing.operator+(total) = ";
	total.Show();
	cout << endl;

	return 0;
}
