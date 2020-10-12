#include <iostream>
using namespace std;
const int Max = 5;

int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
void revalue(double r, double arr[], int n);

int main()
{
	double properties[Max];
	
	int size = fill_array(properties, Max);
	show_array(properties, size);
	cout << "Zadajte koeficient prehodnotenia: ";
	double factor;
	cin >> factor;
	revalue(factor, properties, size);
	show_array(properties, size);
	cout << "Hotovo\n";
	return 0;
}

void revalue(double r, double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] *= r;
	}
}

void show_array(const double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Majetok c." << (i+1) << ": Kc" << arr[i] << endl;
	}
}

int fill_array(double arr[], int limit)
{
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Zadajte hodnotu cislo c." << (i+1) << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Neplatny vstup, zadavanie ukoncene.\n";
			break;
		}
		else if (temp < 0)
		{
			break;
			
		}
		arr[i] = temp;
	}
	
	return i;
}
