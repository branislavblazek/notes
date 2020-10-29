// while.cpp - úvod do cyklu while
#include <iostream>
const int ArSize = 20;
int main()
{
	using namespace std;
	char name[ArSize];

	cout << "Vase krestni jmeno, prosim: ";
	cin >> name;
	cout << "Zde je vase jmeno svisle s ASCII kody:\n";
	int i = 0; 							// start na zaèátku øetìzce
	while (name[i] != '\0') 	// zpracování do konce øetìzce
	{
		cout << name[i] << ": " << int(name[i]) << endl;
		i++; 								// na tento krok nezapomeòte
	}
	
	return 0;
}
