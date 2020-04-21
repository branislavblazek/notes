// arraynew.cpp -- použití operátoru new pro pole
#include <iostream>
int main()
{
	using namespace std;
	double * p3 = new double [3]; 		// místo na 3 double
	p3[0] = 0.2; 									// zachází s p3 jako se jménem pole
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1] je " << p3[1] << ".\n";
	p3 = p3 + 1; 									// inkrementuje ukazatel
	cout << "Nyni je p3[0] " << p3[0] << " a ";
	cout << "p3[1] " << p3[1] << ".\n";
	p3 = p3 - 1; 									// ukazuje zpìt na zaèátek
	delete [] p3; 									// uvolòuje pamì
	
	return 0;
}
