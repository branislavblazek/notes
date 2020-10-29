//další èást stocks.cpp -- implementace metod tøídy
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
		std::cerr << "Pocet akcii nemuze byt zaporny. "
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
		cerr << "Pocet akcii nemuze byt zaporny. "
				<< "Transakce ukoncena.\n";
	}
	else if (num > shares)
	{
		cerr << "Nemuzete prodat vic nez mate! "
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
	cout << "Firma: " << company
			<< " Akcie: " << shares << endl
			<< " Cena akcie: Kc " << share_val
			<< " Celkova cena: Kc" << total_val << endl;
}
