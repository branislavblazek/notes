// stacktem.cpp -- test šablony pro zásobník
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;

int main()
{
	Stack<std::string> st; // vytvoø prázdný zásobník
	char ch;
	std::string po;
	cout << "Pro pridani objednavky zadejte P,\n"
			<< "pro zpracovani Z a pro ukonceni K.\n";
	while (cin >> ch && std::toupper(ch) != 'K')
	{
		while (cin.get() != '\n')
			continue;
	if (!std::isalpha(ch))
	{
		cout << '\a';
			continue;
	}
	switch(ch)
	{
		case 'P':
		case 'p': 	cout << "Zadejte cislo objednavky: ";
							cin >> po;
							if (st.isfull())
								cout << "zasobnik je jiz plny\n";
							else
								st.push(po);
							break;
		case 'Z':
		case 'z': 	if (st.isempty())
								cout << "zasobnik je jiz prazdny\n";
							else {
								st.pop(po);
								cout << "Objednavka c. " << po << " byla zpracovana\n";
								break;
							}
		}
		cout << "Pro pridani objednavky zadejte P,\n"
				<< "pro zpracovani Z a pro ukonceni K.\n";
	}
	cout << "Nashledanou\n";
	return 0;
}
