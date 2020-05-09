#include <iostream>
using namespace std;

int main()
{
	cout << "Zadajte dve platne cisla a, b, pricom a < b: " << endl;
	int a, b;
	cin >> a >> b;
	int sucet = 0, i;
	for (i = a; i <= b; i++)
	{
		sucet += i;
	}
	cout << sucet;
	return 0;
}
