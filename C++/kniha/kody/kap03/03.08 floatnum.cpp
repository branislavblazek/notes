// floatnum.cpp - typy s pohyblivou radovou carkou
#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield); // pevná èárka
	float tub = 10.0 / 3.0; 											// pøesnost asi 6 míst
	double mint = 10.0 / 3.0; 										// pøesnost asi 15 míst
	const float million = 1.0e6;

	cout << "skopek = " << tub;
	cout << ", milion skopku = " << million * tub;
	cout << ",\na deset milionu skopku = ";
	cout << 10 * million * tub << endl;

	cout << "ranec = " << mint << " a milion rancu = ";
	cout << million * mint << endl;

	return 0;
}
