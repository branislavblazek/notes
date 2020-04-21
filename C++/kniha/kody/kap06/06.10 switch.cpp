// switch.cpp -- použití pøíkazu switch
#include <iostream>
using namespace std;
void showmenu(); 			// prototypy funkcí
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
			case 1	:	cout << "\a\n";
							break;
			case 2	:	report();
							break;
			case 3	:	cout << "Vedouci byl pritomen cely den.\n";
							break;
			case 4	:	comfort();
							break;
			default: cout << "To neni volba.\n";
		}
		showmenu();
		cin >> choice;
	}
	cout << "Sbohem!\n";
	return 0;
}
void showmenu()
{
	cout << "Prosim, zadejte 1, 2, 3, 4 nebo 5:\n"
				"1) poplach      2) zprava\n"
				"3) vymluva      4) uklidneni\n"
				"5) ukonceni\n";
}
void report()
{
	cout << "To byl vytecny tyden pro obchod.\n"
		"Trzby vzrostly o 120 %. Vydaje poklesly o 35 %.\n";
}
void comfort()
{
	cout << "Vasi zamestnanci si mysli, ze jste nejlepsi vykonny reditel\n"
				"v branzi. Spravni rada si mysli,\n"
				"ze jste nejlepsi vykonny reditel v branzi.\n";
}
