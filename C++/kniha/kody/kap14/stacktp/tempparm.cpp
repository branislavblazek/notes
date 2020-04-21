// tempparm.cpp -- šablony jako parametry
#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	// pøedpokládá, že tøída thing má èleny push() a pop()
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int & a, double & x){ return s1.pop(a) && s2.pop(x); }
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Crab<Stack> nebula;
// Stack musí být ve shodì s template <typename T> class thing
	int ni;
	double nb;
	cout << "Zadavejte dvojice typu int double, napr. 4 3.5 (0 0 konec):\n";
	while (cin>> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}

	while (nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	cout << "Hotovo.\n";

	return 0;
}

