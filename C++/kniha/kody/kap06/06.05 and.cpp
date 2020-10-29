// and.cpp -- použití logického operátoru A (AND)
#include <iostream>
const int ArSize = 6;
int main()
{
	using namespace std;
	float naaq[ArSize];
	cout << "Zadejte KUNV (Koeficienty uvedomeni noveho veku) "
			<< "\nvasich sousedu. Program konci, "
			<< "kdyz provedete\n" << ArSize << " zadani "
			<< "nebo vlozite zapornou hodnotu.\n";

	int i = 0;
	float temp;
	cout << "Prvni hodnota: ";
	cin >> temp;
	while (i < ArSize && temp >= 0) 		// 2 podmínky ukonèení
	{
		naaq[i] = temp;
		++i;
                if (i < ArSize)
		{
			cout << "Dalsi hodnota: ";
			cin >> temp; 								// dalsi hodnota
		}
	}
	if (i == 0)
		cout << "Zadne udaje-sbohem\n";
	else
	{
		cout << "Zadejte svuj KUNV: ";
		float you;
		cin >> you;
		int count = 0;
		for (int j = 0; j < i; j++)
			if (naaq[j] > you)
				++count;
		cout << count;
		cout << " z vasich sousedu ma vetsi uvedomeni\n"
				<< "Noveho veku, nez vy.\n";
	}
	
	return 0;
}
