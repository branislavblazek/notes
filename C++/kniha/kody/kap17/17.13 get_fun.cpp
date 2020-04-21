// get_fun.cpp -- pouití funkcí get() a getline()
#include <iostream>
const int Limit = 255;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char input[Limit];

	cout << "Zadejte retezec pro zpracovani funkci getline():\n";
	cin.getline(input, Limit, '#');
	cout << "Zadany vstup:\n";
	cout << input << "\nKonec faze 1\n";

	char ch;
	cin.get(ch);
	cout << "Dalsim znakem na vstupu je " << ch << endl;

	if (ch != '\n')
		cin.ignore(Limit, '\n'); // zbytek øádku odloí

	cout << "Zadejte retezec pro zpracovani funkci get():\n";
	cin.get(input, Limit, '#');
	cout << "Zadany vstup:\n";
	cout << input << "\nKonec faze 2\n";

	cin.get(ch);
	cout << "Dalsim znakem na vstupu je " << ch << endl;

	return 0;
}
