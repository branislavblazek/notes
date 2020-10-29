//filefunc.cpp - funkce s parametrem ostream &
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream & os, double fo, const double fe[],int n);
const int LIMIT = 5;
int main(void)
{
	ofstream fout;
	const char * fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "Zadejte ohniskovou vzdalenost "
				"objektivu dalekohledu v mm: ";
	cin >> objective;
	double eps[LIMIT];
	cout << "Zadejte v mm ohniskove vzdalenosti " << LIMIT << " okularu:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Okular #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "Hotovo\n";
	return 0;
}

void file_it(ostream & os, double fo, const double fe[],int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed); // ulož poèáteèní stav formátování
	os.precision(0);
	os << "Ohniskova vzdalenost objektivu: " << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);
	os << "f okularu";
	os.width(15);
	os << "zvetseni" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int (fo/fe[i] + 0.5) << endl;
	}
	os.setf(initial); 	// obnova poèáteèního stavu formátování
}
