// auto.cpp -- ilustrace rozsahu platnosti automatických promìnných
#include <iostream>
void oil(int x);
int main()
{
	using namespace std;

	int texas = 31;
	int year = 1999;
	cout << "V main(), texas = " << texas << ", &texas = ";
	cout << &texas << "\n";
	cout << "V main(), year = " << year << ", &year = ";
	cout << &year << "\n";
	oil(texas);
	cout << "V main(), texas = " << texas << ", &texas = ";
	cout << &texas << "\n";
	cout << "V main(), year = " << year << ", &year = ";
	cout << &year << "\n";
	
	return 0;
}

void oil(int x)
{
	using namespace std;
	int texas = 5;
	cout << "V oil(), texas = " << texas << ", &texas = ";
	cout << &texas << "\n";
	cout << "V oil(), x = " << x << ", &x = ";
	cout << &x << "\n";
	{ 															// zaèátek bloku
		int texas = 113;
		cout << "V bloku, texas = " << texas;
		cout << ", &texas = " << &texas << "\n";
			cout << "V bloku, x = " << x << ", &x = ";
		cout << &x << "\n";
	} 															// konec bloku
	cout << "Za blokem texas = " << texas;
	cout << ", &texas = " << &texas << "\n";
}
