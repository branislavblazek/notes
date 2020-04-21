// strgback.cpp -- funkce, která vrací ukazatel na char
#include <iostream>
char * buildstr(char c, int n); 						// prototyp
int main()
{
	using namespace std;
	int times;
	char ch;

	cout << "Zadejte znak: ";
	cin >> ch;
	cout << "Zadejte cele cislo: ";
	cin >> times;
	char *ps = buildstr(ch, times);
	cout << ps << "\n";
	delete [] ps; // uvolnìní pamìti
	ps = buildstr('+', 20); 								// znovupoužití ukazatele
	cout << ps << "-HOTOVO-" << ps << endl;
	delete [] ps; 													// uvolnìní pamìti
	return 0;
}

// vytváøí øetìzec o n znacích c
char * buildstr(char c, int n)
{
	char * pstr = new char[n + 1];
	pstr[n] = '\0'; 												// ukonèení øetìzce
	while (n-- > 0)
		pstr[n] = c; 												// naplní zbytek øetìzce
	return pstr;
}
