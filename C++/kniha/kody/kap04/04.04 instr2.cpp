// instr2.cpp -- ètení více než jednoho slova pomocí getline
#include <iostream>
int main()
	{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Zadejte vase jmeno:\n";
	cin.getline(name, ArSize); // ète celý øádek
	cout << "Zadejte vas oblibeny zakusek:\n";
	cin.getline(dessert, ArSize);
	cout << "Mam vyborny " << dessert;
	cout << ", ktery si zaslouzi jen " << name << ".\n";
	
	return 0;
}
