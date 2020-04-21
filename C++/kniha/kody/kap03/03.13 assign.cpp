// assign.cpp - zmena typu pri prirazeni
#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3; 				// int se konvertuje na float
	int guess = 3.9832; 		// float se konvertuje na int
	int debt = 7.2E12; 		// výsledek není v C++ definován
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	
	return 0;
}
