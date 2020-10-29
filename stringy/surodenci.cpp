#include <iostream>
#include <string>
using namespace std;

int main()
{
	string vstup;
	cin >> vstup;
	int n = vstup.size();
	int poln = n / 2;
	
	int pocet;
	cin >> pocet;
	
	bool je_symetricke = true;
	
	for (int i = 0; i < poln; i++)
	{
		if (vstup[i] != vstup[n-1-i])
		{
			je_symetricke = false;
			break;
		}
	}
	
	int index;
	char znak;
	
	while (pocet--)
	{
		cin >> index;
		cin >> znak;
		vstup[index] = znak;
		
		if (vstup[index] == vstup[n-1-index])
		{
			cout << "ano" << endl;
		}
		else
		{
			bool ok = true;
			for (int i = 0; i < poln; i++)
			{
				if (vstup[i] != vstup[n-1-i])
				{
					je_symetricke = false;
					cout << "nie" << endl;
					ok = false;
					break;
				}
			}
			if (ok == true)
			{
				cout << "ano" << endl;
				je_symetricke = true;	
			}	
		}
		
	}	
}
