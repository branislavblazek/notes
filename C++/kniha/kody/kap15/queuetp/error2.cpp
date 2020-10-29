// error2.cpp -- návrat chybového kódu
#include <iostream>
#include <cfloat> // (nebo float.h) pro DBL_MAX

bool hmean(double a, double b, double * ans);

int main()
{
	double x, y, z;
	std::cout << " Zadejte dve cisla: ";
	while (std::cin >> x >> y)
	{
		if (hmean(x,y,&z))
			std::cout << "Harmonicky prumer cisel " << x << " a " << y
							<< " je " << z << std::endl;
		else
			std::cout << " Jedna hodnota nesmi byt "
							<< "opakem druhe - opakujte.\n";
		std::cout << "Zadejte dalsi mnozinu cisel <k pro ukonceni>: ";
	}
	std::cout << "Nashledanou!\n";
	return 0;
}

bool hmean(double a, double b, double * ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}
