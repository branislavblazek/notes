// address.cpp -- použití operátoru & na zjištìní adresy
#include <iostream>
int main()
{
	using namespace std;
	int donuts = 6;
	double cups = 4.5;

	cout << "hodnota promenne donuts = " << donuts;
	cout << " a adresa promenne donuts = " << &donuts << endl;
// Poznámka: možná budete muset použít unsigned (&donuts)
// a unsigned (&cups)
	cout << "hodnota promenne cups = " << cups;
	cout << " a adresa promenne cups = " << &cups << endl;
	
	return 0;
}
