#include <iostream>
#include <string>
using namespace std;

int main()
{
	string meno;
	string priezvisko;
	string full;
	
	cout << "Zadajte vase meno:" << endl;
	getline(cin, meno);
	cout << "Zadajte vase priezvisko:" << endl;
	getline(cin, priezvisko);
	
	full = priezvisko + ", " + meno;
	cout << full;
	return 0;
}
