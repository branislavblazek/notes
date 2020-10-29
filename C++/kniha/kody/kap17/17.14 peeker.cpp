// peeker.cpp -- nìkteré metody z istream
#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

//	ète a zobrazuje vstup až do znaku #
	char ch;

	while(cin.get(ch)) // skonèí pøi EOF
	{
		if (ch != '#')
			cout << ch;
		else
		{
			cin.putback(ch); // vloží znak zpìt
			break;
		}
	}
	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << "Dalsim vstupnim znakem je " << ch << ".\n";
	}
	else
	{
		cout << "Konec souboru.\n";
		std::exit(0);
	}

	while(cin.peek() != '#') // pøedem kontroluje vstupní znaky
	{
		cin.get(ch);
		cout << ch;
	}
	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << "Dalsim vstupnim znakem je " << ch << ".\n";
	}
		else
	cout << "Konec souboru.\n";

	return 0;
}
