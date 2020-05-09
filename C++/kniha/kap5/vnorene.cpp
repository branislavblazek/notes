#include <iostream>
using namespace std;

int main()
{
	const int Cities = 5;
	const int Years = 4;
	
	const char * cities[Cities] = 
	{
		"Kosice",
		"Zilina",
		"Bratislava",
		"Trnava",
		"Nitra"
	};
	
	int maxtemps[Years][Cities] = 
	{
		{
			21, 22, 21, 22, 23
		},
		{
			25, 24, 25, 26, 25
		},
		{
			26,24, 23, 24, 21
		},
		{
			25,25,25,25,24
		},
	};
	
	cout << "Maximalne teploty v mestach" << endl;
	for (int city = 0; city < Cities; city++)
	{
		cout << cities[city] << "\t\t";
		for (int year = 0; year < Years; year++)
		{
			cout << maxtemps[year][city] << "\t";
		}
		cout << endl;
	}
	return 0;
}
