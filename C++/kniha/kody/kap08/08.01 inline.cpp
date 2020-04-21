// inline.cpp -- použití vložené (inline) funkce
#include <iostream>

// vložená funkce musí být definována pøed svým prvním použitím
inline double square(double x) { return x * x; }

int main()
{
	using namespace std;
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5); 				// mùže se pøedat výraz
	cout << "a = " << a << ", b = " << b << "\n";
	cout << "c = " << c;
	cout << ", c na druhou = " << square(c++) << "\n";
	cout << "Nyni c = " << c << "\n";
	return 0;
}
