#include <iostream>
using namespace std;

struct inflatable
{
	char name[20];
	float volume;
	int price;
};

int main()
{
	inflatable * ps = new inflatable;
	cout << "Zadajte meno nafukovacieho predmenu: ";
	cin.get(ps -> name, 20); //metoda 1 k pristup ku clenu
	cout << "Zadajte objem v litroch: ";
	cin >> (*ps).volume; // metoda 2 k pristup k clenu
	cout << "Zadajte cenu v EUR: ";
	cin >> ps -> price;
	cout << "Meno: " << (*ps).name << endl; //metoda 2
	cout << "Objem: " << ps->volume << endl; //metoda 1
	cout << "Cena: " << ps->price << endl; //metoda 1
	delete ps;
	
	return 0;
}
