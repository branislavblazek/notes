#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	string dessert;
	
	cout << "Zadajte vase meno:" << endl;
	getline(cin, name);
	cout << "Zadajte vas oblubeny zakusok:" << endl;
	getline(cin, dessert);
	cout << "Mam vyborny " << dessert << " ktory si zasluzi len " << name << endl;
}
