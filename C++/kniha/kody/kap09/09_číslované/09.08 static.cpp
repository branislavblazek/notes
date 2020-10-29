// static.cpp -- použití statické lokální promìnné
#include <iostream>
// konstanty
const int ArSize = 10;

// prototyp funkce
void strcount(const char * str);

int main()
{
	using namespace std;
	char input[ArSize];
	char next;

	cout << "Zadejte radek textu:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n') // øetìzec se nevešel!
			cin.get(next);
		strcount(input);
		cout << "Zadejte dalsi radek textu (prazdny radek na ukonceni):\n";
		cin.get(input, ArSize);
	}
	cout << "Sbohem\n";
	return 0;
}

void strcount(const char * str)
{
	using namespace std;
	static int total = 0; // statická lokální promìnná
	int count = 0; // automatická lokální promìnná

	cout << "\"" << str <<"\" obsahuje ";
	while (*str++) // jde na konec øetìzce
		count++;
	total += count;
	cout << count << " znaku\n";
	cout << total << " znaku celkem\n";
}
