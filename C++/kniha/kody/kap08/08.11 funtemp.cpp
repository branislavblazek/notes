// funtemp.cpp -- použití šablony funkce
#include <iostream>
// prototyp šablony funkce
template <class Any> // nebo typename Any
void Swap(Any &a, Any &b);
int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Funkce pro zamenu cisel typu int generovana prekladacem:\n";
	Swap(i,j); 		// generuje void Swap(int &, int &)
	cout << "Nyni i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << " Funkce pro zamenu cisel typu double generovana prekladacem:\n";
	Swap(x,y); 		// generuje void Swap(double &, double &)
	cout << "Nyni x, y = " << x << ", " << y << ".\n";

	return 0;
}

// definice šablony funkce
template <class Any> // nebo typename Any
void Swap(Any &a, Any &b)
{
	Any temp; 	// temp je promìnná typu Any
	temp = a;
	a = b;
	b = temp;
}
