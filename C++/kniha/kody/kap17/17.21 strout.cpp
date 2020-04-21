// strout.cpp -- formátování incore do výstupního toku
#include <iostream>
#include <sstream>
#include <string>
int main()
{
	using namespace std;
	ostringstream outstr; // spravuje øetìzcový tok

	string hdisk;
	cout << "Jak se jmenuje vas pevny disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "Jaka je jeho kapacita v GB? ";
	cin >> cap;
	// zápis formátovaných informací do øetìzcového toku
	outstr << "Pevny disk " << hdisk << " ma kapacitu "
				<< cap << " gigabajtu.\n";
	string result = outstr.str(); // uloží výsledek
	cout << result; // vypíše obsah

	return 0;
}
