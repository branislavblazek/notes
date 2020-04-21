// twoarg.cpp -- funkce se dvìma parametry
#include <iostream>
using namespace std;
void n_chars(char, int);
int main()
{
	int times;
	char ch;

	cout << "Zadejte znak: ";
	cin >> ch;
	while (ch != 'q') 				// q pro ukonèení
{
	cout << "Zadejte cele cislo: ";
	cin >> times;
	n_chars(ch, times); // funkce se dvìma parametry
	cout << 	"\nZadejte dalsi znak, nebo stisknete"
					" klavesu q pro ukonceni: ";
		cin >> ch;
	}
	cout << "Hodnota promenne times je " << times << ".\n";
	cout << "Sbohem\n";
	return 0;
}

void n_chars(char c, int n) 		// zobrazí c n-krát
{
while (n-- > 0) 			// pokraèuje, dokud nemá n hodnotu 0
cout << c;
}
