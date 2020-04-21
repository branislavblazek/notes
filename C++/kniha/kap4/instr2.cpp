#include <iostream>
using namespace std;

int main()
{
	const int ArrSize = 40;
	char name[ArrSize];
	char dessert[ArrSize];
	
	cout << "Zadajte vase meno: " << endl;
	cin.getline(name, ArrSize);
	cout << "Zadajte nazov kolaca: " << endl;
	cin.getline(dessert, ArrSize);
	
	cout << "Mam vyborny " << dessert << ", ktory si zasluzi len " << name << endl;
}
