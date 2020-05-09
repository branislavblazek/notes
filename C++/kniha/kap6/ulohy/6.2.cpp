#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 10;
	double numbers[SIZE];
	cout << "Prve cislo je: " << endl;
	int i = 0;
	while (i < SIZE && cin >> numbers[i])
	{
		cout << "Dalsie cislo vlozene!" << endl;
		if (++i < SIZE)
			cout << "Dalsie cislo je: " << endl;
	}
	
	double total = 0.0;
	for (int j = 0; j < i; j++)
	{
		total += numbers[j];
	}
	double priemer = total / i;
	int pocet_bigger = 0;
	for (int k = 0; k < i; k++)
	{
		if (numbers[k] > priemer)
		{
			pocet_bigger++;
		}
	}
	cout << "Spolu davaju sucet " << total << ", ich priemer je " << priemer << " a " << pocet_bigger << " cisiel je vacsich ako " << priemer << endl;
	return 0;
}
