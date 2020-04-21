// instr3.cpp -- ètení více než jednoho slova pomocí get() & get()
#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Zadejte vase jmeno:\n";
	cin.get(name, ArSize).get(); 		// ète øetìzec, nový øádek
	cout << "Zadejte vas oblibeny zakusek:\n";
	cin.get(dessert, ArSize).get();
	cout << "Mam vyborny " << dessert;
	cout << ", ktery si zaslouzi jen " << name << ".\n";
	return 0;
}
