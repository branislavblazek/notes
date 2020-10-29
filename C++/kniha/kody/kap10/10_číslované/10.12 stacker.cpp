// stacker.cpp -- test tøídy Stack
#include <iostream>
#include <cctype> // nebo ctype.h
#include "stack.h"
int main()
{
	using namespace std;
	Stack st; // vytvoøí prázdný zásobník
	char ch;
	unsigned long po;
	cout << "Pro pridani objednavky zadejte P,\n"
			<< "Pro zpracovani Z, pro ukonceni K.\n";
	while (cin >> ch && toupper(ch) != 'K')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch(ch)
		{
			case 'P':
			case 'a': 	cout << "Zadejte cislo objednavky: ";
								cin >> po;
								if (st.isfull())
									cout << " zasobnik je jiz plny \n";
								else
									st.push(po);
								break;
			case 'Z':
			case 'z': 	if (st.isempty())
									cout << " zasobnik je jiz prazdny \n";
								else {
									st.pop(po);
									cout << " Objednavka c." << po << " byla zpracovana\n";
								}
								break;
		}
		cout << "Pro pridani objednavky zadejte P,\n"
				<< "Pro zpracovani Z, pro ukonceni K.\n";
	}
	cout << "Nashledanou\n";
	return 0;
}
