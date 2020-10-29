// strfile.cpp -- ètení øetìzcù ze souboru
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
int main()
{
	using namespace std;
	ifstream fin;
	fin.open("nakup.txt");
	if (fin.is_open() == false)
	{
		cerr << "Soubor nelze otevøít. Nazdar.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;

	getline(fin, item, ':');
	while (fin) 			// pokud je vstup v poøádku
	{
		++count;
		cout << count <<": " << item << endl;
		getline(fin, item,':');
	}
	cout << "Hotovo\n";
	fin.close();
	return 0;
}
