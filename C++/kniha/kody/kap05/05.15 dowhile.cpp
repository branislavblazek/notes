// dowhile.cpp -- výstupní podmínka cyklu
#include <iostream>
int main()
{
	using namespace std;
	int n;

	cout << "Zadavejte cisla v rozmezi 1-10, abyste nasli ";
	cout << "me oblibene cislo\n";
	do
	{
		cin >> n; 			// provádí tìlo
	} while (n != 7); 	// potom testuje
	cout << "Ano, 7 je me oblibene cislo.\n" ;
	
	return 0;
}
