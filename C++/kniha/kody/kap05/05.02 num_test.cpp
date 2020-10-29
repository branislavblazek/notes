// num_test.cpp -- použijte numerický test v cyklu for
#include <iostream>
int main()
{
	using namespace std;
	cout << "Zadejte pocatecni odpocitavaci hodnotu: ";
	int limit;
	cin >> limit;
	int i;
	for (i = limit; i; i--) 	// konec, když je i rovno 0
		cout << "i = " << i << "\n";
	cout << "Hotovo, nyni je i = " << i << "\n";
	
	return 0;
}
