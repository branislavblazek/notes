#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double area;
	cout << "Zadajte vymeru podlahy svojho domu v stvorcovych metroch. ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "To je ekvivalent stvorca o strane " << side << " metrov." << endl;
	return 0;
}
