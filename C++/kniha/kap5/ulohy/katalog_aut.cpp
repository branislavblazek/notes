#include <iostream>
using namespace std;

struct car 
{
	char name[50];
	int year;
};

int main()
{
	int n;
	cout << "Kolko aut chcete zadat? ";
	cin >> n;
	
	while (cin.get() != '\n');
	car * pc = new car[n];
	
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Auto c. " << (i+1) << endl;
		cout << "Zadajte znacku: ";
		cin.getline(pc[i].name, 20);
		cout << "Zadajte rok vyroby: ";
		cin >> pc[i].year;
		while (cin.get() != '\n');	
	}
	cout << "Tu je vasa kolekcia: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << pc[i].name << " z roku " << pc[i].year << endl;
	}
	delete [] pc;
	return 0;
}
