#include <iostream>
using namespace std;
//prototyp funkcie
void simon(int);

int main()
{
	simon(3);
	cout << "Vyberte si cele cislo: ";
	int count;
	cin >> count;
	simon(count);
	cout << "Hotovo!" << endl;
	
	return 0;
}

void simon(int n)
{
	cout << "Simon hovori, aby si sa dotkol prsta na nohe " << n << " krat." << endl;
}
