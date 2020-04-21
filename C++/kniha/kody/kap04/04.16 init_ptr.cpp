// init_ptr.cpp -- inicializuje ukazatel
#include <iostream>
int main()
{
	using namespace std;
	int higgens = 5;
	int * pt = &higgens;

	cout << "Hodnota higgens = " << higgens
			<< "; Adresa higgens = " << &higgens << "\n";
	cout << "Hodnota *pt = " << *pt
			<< "; Hodnota pt = " << pt << "\n";
			
	return 0;
	}
