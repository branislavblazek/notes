#include <iostream>
using namespace std;

int main(void)
{
	int husy = 5;
	int * ph = &husy;
	
	cout << "Hodnota husy = " << husy << "; Adresa husy = " << &husy << endl;
	cout << "Hodnota *ph = " << *ph << "; Hodnota ph " << ph << endl;
	
	return 0;
}
