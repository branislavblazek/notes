// stock2.cpp -- vylepšená verze
#include <iostream>
#include "stock2.h"
// constructors
Stock::Stock() // implicitní konstruktor
{
	std::strcpy(company, "bezejmenna");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr)
{
	std::strncpy(company, co, 29);
	company[29] = '\0';

	if (n < 0)
	{
		std::cerr << "Pocet akcii nemuze byt zaporny; akcie"
						<< company << " nastaveny na 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
// destruktor tøídy
Stock::~Stock() // tichý destruktor tøídy
{
}
// ostatní metody
void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		std::cerr << "Pocet nakupovanych akcii nemuze byt zaporny. "
						<< "Transakce ukoncena.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0)
	{
		cerr << "Pocet prodavanych akcii nemuze byt zaporny. "
				<< "Transakce ukoncena.\n";
	}
	else if (num > shares)
	{
		cerr << "Nemuzete prodavat vic akcii nez mate! "
		<< "Transakce ukoncena.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	using std::cout;
	using std::endl;
	cout << "Spolecnost: " << company
			<< " Akcie: " << shares << endl
			<< " Cena akcii: $" << share_val
			<< " Celkova cena: $" << total_val << endl;
}
const Stock & Stock::topval(const Stock & s) const
{
if (s.total_val > total_val)
return s;
else
return *this;
}
