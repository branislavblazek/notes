// waiting.cpp -- použití funkce clock() ve zpožïovací smyèce
#include <iostream>
#include <ctime> // popisuje funkci clock() a typ clock_t
int main()
{
	using namespace std;
	cout << "Zadejte zpozdeni v sekundach: ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC; 	// pøevede na hodinové takty
	cout << "zacatek\a\n";
	clock_t start = clock();
	while (clock() - start < delay ) 				// èekání do vypršení èasu
	; 																	// všimnìte si støedníku
cout << "konec \a\n";

return 0;
}
