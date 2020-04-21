// cubes.cpp - normální a odkazové argumenty
#include <iostream>
double cube(double a);
double refcube(double &ra);
int main ()
{
	using namespace std;
	double x = 3.0;

	cout << cube(x);
	cout << " = treti mocnina ze " << x << endl;
	cout << refcube(x);
	cout << " = treti mocnina z " << x << endl;
	return 0;
}

double cube(double a)
{
	a *= a * a;
	return a;
}

double refcube(double &ra)
{
	ra *= ra * ra;
	return ra;
}
