// exceed.cpp -- pøekroèení nìkterých celoèíselných omezení
#include <iostream>
#define ZERO 0 			// symbol ZERO bude mít hodnotu 0
#include <climits> 	// definuje INT_MAX jako nejvìtší celoèíselnou hodnotu
int main()
{
	using namespace std;
	short sam = SHRT_MAX; 			// inicializuje promìnnou na maximální hodnotu
	unsigned short sue = sam; 	// v poøádku, je-li promìnná sam již definována

	cout << "Sam ma ulozeno " << sam << " dolaru a Sue " << sue;
	cout << " dolaru." << endl
			<< "Na kazdy ucet pridame 1 dolar." << endl << "Nyni ";
	sam = sam + 1;
	sue = sue + 1;
	cout << "ma Sam ulozeno " << sam << " dolaru a Sue " << sue;
	cout << " dolaru.\nChudak Sam!" << endl;
	sam = ZERO;
	sue = ZERO;
	cout << "Sam ma ulozeno " << sam << " dolaru a Sue " << sue;
	cout << " dolaru." << endl;
	cout << "Z kazdeho uctu vezmeme 1 dolar." << endl << "Nyni ";
	sam = sam - 1;
	sue = sue - 1;
	cout << "ma Sam ulozeno " << sam << " dolaru a Sue " << sue;
	cout << " dolaru." << endl << "Stastna Sue!" << endl;
	
	return 0;
}
