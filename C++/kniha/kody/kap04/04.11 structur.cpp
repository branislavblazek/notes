// structur.cpp -- jednoduchá struktura
#include <iostream>
struct inflatable // šablona struktury
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable guest =
	{
		"Glorious Gloria", // hodnota name
		1.88, 						// hodnota volume
		29.99 						// hodnota price
	}; 								// guest je strukturní promìnnou typu inflatable
// inicializuje se uvedenými hodnotami
	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	}; 	// pal je druhou promìnnou typu inflatable
// Poznámka: nìkteré implementace vyžadují použití
// static inflatable guest =

	cout << "Rozsirte vas seznam hostu o " << guest.name;
	cout << " a " << pal.name << "!\n";
// zápis pal.name znamená, že name je èlenem promìnné pal
	cout << "Oba ziskate za ";
	cout << (guest.price + pal.price) << " Kc!\n";
	
	return 0;
}
