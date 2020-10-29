#include <iostream>
using namespace std;

int main()
{
	cout << "V ktorom roku bol postavny vas dom? " << endl;
	int year;
	cin >> year;
	cin.get();
	cout << "Aka je jeho adresa? " << endl;
	char adress[80];
	cin.getline(adress, 80);
	cout << "Rok vystavby: " << year << endl;
	cout << "Adresa: " << adress << endl;
	
	return 0;
}
