#include <iostream>
#include <string>
using namespace std;

struct inflatable
{
	string name;
	float volume;
	double price;
};

int main()
{
	inflatable guest = 
	{
		"Glorious Gloria",
		1.88,
		29.99
	};
	inflatable pal = 
	{
		"Audacious Arthur",
		3.12,
		32.99
	};
	
	cout << "Rozsirte vas zoznam hostov o " << guest.name << " a " << pal.name << endl;
	cout << "Oboch ziskate za " << (guest.price + pal.price) << endl;
	cout << pal.name.size();
	
	return 0;
}
