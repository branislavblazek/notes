//error1.cpp -- použití funkce abort()
#include <iostream>
#include <cstdlib>
double hmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "Zadejte dve cisla: ";
	while (std::cin >> x >> y)
	{
		z = hmean(x,y);
		std::cout << "Harmonicky prumer cisel " << x << " and " << y
						<< " is " << z << std::endl;
		std::cout << "Zadejte dalsi mnozinu cisel <k pro ukonceni>: ";
	}
	std::cout << "Nashledanou!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "neplatne parametry ve funkci hmean()\n";
		std::abort();
	}
	return 2.0 * a * b / (a + b);
}
