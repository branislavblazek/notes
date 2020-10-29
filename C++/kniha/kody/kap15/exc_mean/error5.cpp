//error5.cpp -- vracení zásobníku
#include <iostream>
#include <cmath> // nebo math.h, uzivatele unixu mozna priznak -lm
#include <cstring>
#include "exc_mean.h"

class demo
{
private:
	char word[40];
public:
	demo (const char * str)
	{
		std::strcpy(word, str);
		std::cout << "demo " << word << " vytvoren\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " zrusen\n";
	}
	void show() const
	{
		std::cout << "demo " << word << " zije!\n";
	}
};

// prototypy funkcí
double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);
double means(double a, double b) throw(bad_hmean, bad_gmean);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	demo d1("nalezeno v main()");
	cout << "Zadejte dve cisla: ";
	while (cin >> x >> y)
	{
		try { // start of try block
			z = means(x,y);
			cout << "Prumer prumeru " << x << " a " << y
					<< " je " << z << endl;
			cout << "Zadejte dalsi dvojici: ";
		}// konec bloku try
		catch (bad_hmean & bg) // zacatek bloku catch 
		{
			bg.mesg();
			cout << "Opakujte.\n";
			continue;
		}
		catch (bad_gmean & hg)
		{
			cout << hg.mesg();
			cout << "Pouzite hodnoty: " << hg.v1 << ", "
					<< hg.v2 << endl;
			cout << "Lituji, hra skoncila.\n";
			break;
		} // konec bloku catch
	}
	d1.show();
	cout << "Nashledanou!\n";
	return 0;
}

double hmean(double a, double b) throw(bad_hmean)
{
	if (a == -b)
		throw bad_hmean(a,b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a,b);
	return std::sqrt(a * b);
}

double means(double a, double b) throw(bad_hmean, bad_gmean)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0; // aritmeticky prumer
	try
	{
		hm = hmean(a,b);
		gm = gmean(a,b);
	}
	catch (bad_hmean & bg) // zacatek bloku catch
	{
		bg.mesg();
		std::cout << "Zachyceno v means()\n";
		throw; // znovuvyvolani vyjimky
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}
