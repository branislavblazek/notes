// stocks.cpp -- celý program
#include <iostream>
#include <cstring>

class Stock 	// deklarace tøídy
{
private:
	char company[30];
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	void acquire(const char * co, int n, double pr);
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	void show();
}; 					// støedník na konci!

void Stock::acquire(const char * co, int n, double pr)
{
	std::strncpy(company, co, 29); // zkrácení co podle company
	company[29] = '\0';
	if (n < 0)
	{
		std::cerr << "Pocet akcii nemuze byt zaporny; "
						<< company << " nastaveni shares na 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

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
		cerr << "Nemuzete prodat vic akcii nez mate! "
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

void Stock::show()
{
	using std::cout;
	using std::endl;
	cout << "Spolecnost: " << company
			<< "  Akcie: " << shares << endl
			<< "  Cena akcie: $" << share_val
			<< "  Celkova hodnota: $" << total_val << endl;
}

int main()
{
	using std::cout;
	using std::ios_base;
	Stock stock1;
	stock1.acquire("NanoSmart", 20, 12.50);
	cout.setf(ios_base::fixed); 				// #.## formát
	cout.precision(2); 							// #.## formát
	cout.setf(ios_base::showpoint); 		// #.## formát
	stock1.show();
	stock1.buy(15, 18.25);
	stock1.show();
	stock1.sell(400, 20.00);
	stock1.show();
	return 0;
} 
