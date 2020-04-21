#include <iostream>
using namespace std;
int fur_to_yard(int);

int main(void)
{
	int furlong;
	cout << "Zadajte vzdialenost vo Furlongoch: ";
	cin >> furlong;
	int yard;
	yard = fur_to_yard(furlong);
	cout << furlong << " Furlongov je " << yard << " yardov" << endl;
	
}

int fur_to_yard(int distance)
{
	return 220 * distance;
}
