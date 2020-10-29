#include <iostream>
using namespace std;

void showmenu();
void report();
void comfort();

int main()
{
	showmenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		switch(choice)
		{
			case 1: cout << "\a\n";
					break;
			case 2: report();
					break;
			case 3: cout << "Veduci bbol pritomni cely den.\n";
					break;
			case 4: comfort();
					break; 
			default: cout << "Pohode?\n";
		}
		showmenu();
		cin >> choice;
	}
	cout << "Ahoj" << endl;
	return 0;
}

void showmenu()
{
	cout << "Prosim zadajte 1, 2, 3, 4 alebo 5:\n"
			"1) poplach		2) sprava\n"
			"3) vyhovorka	4) ukludnenie\n"
			"5) koniec\n";
}

void report()
{
	cout << "Toto bol super tyzden pre obchod\n"
			"Nas produkt si kupil prvy nahodny zakaznik!\n";
}

void comfort()
{
	cout << "Si super\n"; 
}
