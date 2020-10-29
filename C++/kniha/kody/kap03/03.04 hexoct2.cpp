// hexoct2.cpp - výpis hexadecimálních a oktalových hodnot
#include <iostream>
using namespace std;
int main()
{
	using namespace std;
	int chest = 76;
	int waist = 76;
	int inseam = 76;

	cout << "Pan ma pozoruhodnou postavu!" << endl;
	cout << "hrudnik = " << chest << " (dekadicky)" << endl;
	cout << hex; 				// manipulaèní symbol pro zmìnu základu èíselné soustavy
	cout << "pas = " << waist << " hexadecimalne" << endl;
	cout << oct; 				// manipulaèní symbol pro zmìnu základu èíselné soustavy
	cout << "sed = " << inseam << " (oktalove)" << endl;
	return 0;
}
