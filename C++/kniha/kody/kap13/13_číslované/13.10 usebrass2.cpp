// usebrass2.cpp -- pøíklad na polymorfii
// compile with brass.cpp
#include <iostream>
#include "brass.h"
const int CLIENTS = 4;
const int LEN = 40;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	Brass * p_clients[CLIENTS];

	int i;
	for (i = 0; i < CLIENTS; i++)
	{
		char temp[LEN];
		long tempnum;
		double tempbal;
		char kind;
		cout << "Zadejte jmeno klienta: ";
		cin.getline(temp, LEN);
		cout << "Zadejte cislo uctu klienta: ";
		cin >> tempnum;
		cout << "Zadejte vstupni zustatek: $";
		cin >> tempbal;
		cout << "Zadejte 1 po ucet Brass nebo "
				<< "2 pro ucet BrassPlus: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout <<"Zadejte bud 1 nebo 2: ";
		if (kind == '1')
		p_clients[i] = new Brass(temp, tempnum, tempbal);
	else
	{
			double tmax, trate;
			cout << "Zadejte limit prekroceni: $";
			cin >> tmax;
			cout << "Zadejte urokovou sazbu "
					<< "jako destinne cislo: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
														tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i]; // uvolni pamet
	}
	cout << "Hotovo.\n";

	return 0;
}
