// iomanip.cpp - použití manipulátorù z hlavièkového souboru iomanip
// nìkteré systémy vyžadují explicitní vazbu na matematickou knihovnu
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	using namespace std;
	// použití nových standardních manipulátorù
	cout << showpoint << fixed << right;

	// použití manipulátorù z iomanip
	cout << setw(6) << "N" << setw(14) << " druha odmocnina"
			<< setw(15) << " ctvrta odmocnina\n";

	double root;
	for (int n = 10; n <=100; n += 10)
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('.') << n << setfill(' ')
				<< setw(12) << setprecision(3) << root
				<< setw(14) << setprecision(4) << sqrt(root)
				<< endl;
	}
	return 0;
}
