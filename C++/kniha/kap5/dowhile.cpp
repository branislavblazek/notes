#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Hadajte moje oblubene cislo" << endl;
	do 
	{
		cin >> n;
	}
	while (n != 6);
	cout << "Spravne, je to 6" << endl;
	return 0;
}
