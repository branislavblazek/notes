// ifelseif.cpp -- použití if else if else
#include <iostream>
const int Fave = 27;
int main()
{
	using namespace std;
	int n;

	cout << "Zkuste najit moje oblibene cislo. ";
	cout << "Zadejte cislo v rozsahu 1-100: ";
	do
	{
		cin >> n;
		if (n < Fave)
			cout << "Prilis nizke -- hadejte znovu: ";
		else if (n > Fave)
			cout << "Prilis vysoke -- hadejte znovu: ";
		else
			cout << Fave << " je spravne!\n";
	} while (n != Fave);
	
	return 0;
} 
