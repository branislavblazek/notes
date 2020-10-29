// instr1.cpp -- ètení více než jednoho øetìzce
#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Zadejte vase jmeno:\n";
	cin >> name;
	cout << "Zadejte vas oblibeny zakusek:\n";
	cin >> dessert;
	cout << "Mam vyborny " << dessert;
	cout << ", ktery si zaslouzi jen " << name << ".\n";
	
	return 0;
}
