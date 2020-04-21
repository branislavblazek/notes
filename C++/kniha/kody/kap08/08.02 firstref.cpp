// firstref.cpp -- definování a použití odkazu (reference)
#include <iostream>
int main()
{
	using namespace std;
	int krysy = 101;
	int & hlodavci = krysy; 	// hlodavci je odkaz (reference)

	cout << "krysy = " << krysy;
	cout << ", hlodavci = " << hlodavci << endl;
	hlodavci++;
	cout << "krysy = " << krysy;
	cout << ", hlodavci = " << hlodavci << endl;

// nìkteré implementace vyžadují pøetypování následujících
// adres na typ unsigned
	cout << "adresa krys = " << &krysy;
	cout << ", adresa hlodavcu = " << &hlodavci << endl;
	return 0;
}
