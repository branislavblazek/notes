#include <iostream>
using namespace std;

int main()
{
	const int ArrSize = 20;
	char name[ArrSize];
	char dessert[ArrSize];
	
	cout << "Zadajte vase meno: " << endl;
	cin.get(name, ArrSize).get();
	cout << "Zadajte vas oblubeny zakusok: " << endl;
	cin.get(dessert, ArrSize).get();
	
	cout << "Mam vyborny " << dessert << ", ktory je pre " << name << endl;
}
