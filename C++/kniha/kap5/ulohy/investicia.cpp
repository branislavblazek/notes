#include <iostream>
using namespace std;

int main()
{
	int zaciatok = 100;
	
	double daphe_ucet = 100;
	double daphe_urok = 0.1;
	
	double cleo_ucet = 100;
	double cleo_urok = 0.05;
	
	int rok = 0;
	
	while (daphe_ucet >= cleo_ucet)
	{
		daphe_ucet += zaciatok * daphe_urok;
		cleo_ucet += cleo_ucet * cleo_urok;
		rok++;
	}
	cout << rok << endl;
	cout << daphe_ucet << endl;
	cout << cleo_ucet << endl;
	return 0;
}
