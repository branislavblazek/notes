// bondini.cpp -- pouziti escape sekvenci
#include <iostream>
int main()
{
	using namespace std;
	cout << "\aOperace \"HyperHype\" je nyni aktivovana!\n";
	cout << "Zadejte svuj tajny kod:________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\aZadal jste " << code << "...\n";
	cout << "\aKod overen! Spustte plan Z3!\n";
	
	return 0;
}
