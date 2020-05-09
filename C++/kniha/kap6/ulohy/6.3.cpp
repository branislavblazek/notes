#include <iostream>
using namespace std;

int main()
{
	cout << "Prosim zadajte jednu z nasledovnych moznosti: " << endl;
	cout << "m) masozravec		p) pianista\n"
			"s) strom			h) hra" << endl;
	char ch;
	cin >> ch;
	while (ch != 'm' and ch != 'p' and ch != 's' and ch != 'h')
	{
		cout << "Zadajte prosim m, p, s alebo h" << endl;
		cin >> ch;
	}
	switch(ch)
	{
		case 'm':	cout << "Pes je masozravec" << endl;
					break;
		case 'p':	cout << "Pianista je pekny film" << endl;
					break;
		case 's': 	cout << "Lipa je strom" << endl;
					break;
		case 'h': 	cout << "Dirt3 showdown je hra" << endl;
					break;
	}
	return 0;
}
