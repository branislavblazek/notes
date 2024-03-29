// manip.cpp -- formátování pomocí manipulátorů
#include <iostream>
int main()
{
	using namespace std;
	cout << "Zadejte cele cislo: ";
	int n;
	cin >> n;

	cout << "n n*n\n";
	cout << n << " " << n * n << " (desitkove)\n";

// nastavení šestnáctkového režimu
	cout << hex;
	cout << n << " ";
	cout << n * n << " (sestnactkove)\n";

// nastavení osmičkového režimu
	cout << oct << n << " " << n * n << " (osmickove)\n";

// alternativní způsob volání manipulátoru
	dec(cout);
	cout << n << " " << n * n << " (desitkove)\n";

	return 0;
}
