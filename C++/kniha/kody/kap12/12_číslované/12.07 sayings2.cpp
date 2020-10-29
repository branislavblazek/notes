// sayings2.cpp -- použití ukazatelù na objekty
// pøeložit spoleènì se string1.cpp
#include <iostream>
#include <cstdlib> // (nebo stdlib.h) pro rand(), srand()
#include <ctime> // (nebo time.h) pro time()
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
	using namespace std;
	String name;
	cout <<" Dobry den, jak se jmenujete?\n>> ";
	cin >> name;

	cout << name << ",zadejte prosim az " << ArSize
			<< "kratkych rceni <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen]; // pamì_ pro doèasný øetìzec
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i+1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
		continue;
	if (!cin || temp[0] == '\0') // prázdný øádek?
		break; // i not incremented
		else
	sayings[i] = temp; // pøetížené pøiøazení
	}
	int total = i; // celkový poèet pøeètených øádkù

	if (total > 0)
	{
	cout << "Zadali jste tato rceni:\n";
		for (i = 0; i < total; i++)
			cout << sayings[i] << "\n";

// použití ukazatelù k evidenci nejkratšího a prvního øetìzce
		String * shortest = &sayings[0];// inicializace prvním objektem
		String * first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first) // porovnání hodnot
				first = &sayings[i]; // pøiøadí adresu
		}
		cout << "Nejkratsi rceni:\n" << * shortest << endl;
		cout << "Prvni rceni podle abecedy:\n" << * first << endl;

		srand(time(0));
		int choice = rand() % total; // náhodný výbìr indexu
// použití operátoru new k vytvoøení objektu tøídy String a jeho inicializace
		String * favorite = new String(sayings[choice]);
		cout << "Moje oblibene rceni:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "Dosla vam rec, co?\n";
	cout << "Nashledanou.\n";
	return 0;
}
