// nested.cpp -- vnoøené cykly a 2-D pole
#include <iostream>
const int Cities = 5;
const int Years = 4;
int main()
{
	using namespace std;
	const char * cities[Cities] = 			// pole ukazatelù
	{ 															// na 5 øetìzcù
		"Gribble City",
		"Gribbleton",
		"New Gribble",
		"San Gribble",
		"Gribble Vista"
	};

	int maxtemps[Years][Cities] = 			// 2-D pole
	{
		{34, 31, 29, 38, 38}, 					// hodnoty pro maxtemps[0]
		{36, 33, 32, 41, 40}, 					// hodnoty pro maxtemps[1]
		{33, 32, 31, 38, 39}, 					// hodnoty pro maxtemps[2]
		{32, 37, 30, 40, 38} 						// hodnoty pro maxtemps[3]
	};

	cout << "Maximalni teploty v letech 2002 - 2005\n\n";
	for (int city = 0; city < Cities; ++city)
	{
		cout << cities[city] << ":\t";
		for (int year = 0; year < Years; ++year)
			cout << maxtemps[year][city] << "\t";
		cout << endl;
	}

	return 0;
}
