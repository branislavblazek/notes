// modulus.cpp -- použití operátoru % pøi konverzi liber na kameny
#include <iostream>
int main()
{
	using namespace std;
	const int Lbs_per_stn = 14;
	int lbs;

	cout << "Zadejte svoji vahu v librach: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn; // celé kameny
	int pounds = lbs % Lbs_per_stn; // zbytek v librách
	cout << lbs << " liber je " << stone
			<< " kamenu, " << pounds << " liber.\n";
			
	return 0;
}
