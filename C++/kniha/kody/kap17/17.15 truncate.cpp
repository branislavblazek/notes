// truncate.cpp -- v pøípadì nutnosti zkrátí vstupní øádek pomocí
#include <iostream>
const int SLEN = 10;
inline void eatline() { while (std::cin.get() != '\n') continue; }
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	char name[SLEN];
	char title[SLEN];
	cout << "Zadejte jmeno: ";
	cin.get(name,SLEN);
	if (cin.peek() != '\n')
		cout << "Misto je bohuzel pouze pro "
				<< name << endl;
	eatline();
	cout << "Dobry den " << name << ", zadejte funkci: \n";
	cin.get(title,SLEN);
	if (cin.peek() != '\n')
		cout << "Byli jsme nuceni funkci zkratit.\n";
	eatline();
	cout << "Jmeno: " << name
			<< "\nFunkce: " << title << endl;

	return 0;
}
