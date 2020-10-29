#include <iostream>
using namespace std;

const double KM_to_Miles = 62.14;
const double galon_to_liter = 3.875;

int main()
{
	double euro_rating;
	double usa_rating;
	cout << "Zadajte spotrebu benzinu v litroch na 100km: ";
	cin >> euro_rating;
	usa_rating = (galon_to_liter * KM_to_Miles) / euro_rating;
	cout << usa_rating << endl;
	
	return 0;
}
