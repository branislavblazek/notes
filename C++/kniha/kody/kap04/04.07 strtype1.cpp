// strtype1.cpp -- using the C++ string class
#include <iostream>
#include <string> // make string class available
int main()
{
	using namespace std;
	char charr1[20]; 						// vytvoø prázdné pole
	char charr2[20] = "jaguar"; 		// vytvoø a inicializuj pole
	string str1; 								// vytvoø prázdný øetìzcový objekt
	string str2 = "panter"; 			// vytvoø a inicializuj øetìzec

	cout << "Zadej kockovitou selmu: ";
	cin >> charr1;
	cout << "Zadej jinou kockovitou selmu: ";
	cin >> str1; // use cin for input
	cout << "Zde jsou kockovite selmy:\n";
	cout << charr1 << " " << charr2 << " "
			<< str1 << " " << str2 		// výstup prostøednictvím cout
			<< endl;
	cout << "Treti pismeno v " << charr2 << " je "
			<< charr2[2] << endl;
	cout << "Treti pismeno v " << str2 << " je "
			<< str2[2] << endl; 			// zápis typu pole

	return 0;
}
