#include <iostream>
using namespace std;

int main()
{
	cout << "Zadajte pociatocnu odpocitavaciu hodnotu: ";
	int limit;
	cin >> limit;
	int i;
	for (i = limit; i; i--)
	{
		cout << "i = " << i << endl;
	}
	cout << "Hotovo, teraz je i = " << i << endl;
	return 0;
}
