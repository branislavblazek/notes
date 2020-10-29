// jump.cpp -- použití continue a break
#include <iostream>
const int ArSize = 80;
int main()
{
	using namespace std;
	char line[ArSize];
	int spaces = 0;

	cout << "Zadejte textovy radek:\n";
	cin.get(line, ArSize);
	cout << "Cely radek:\n" << line << endl;
	cout << "Radek po prvni tecku:\n";

	for (int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i]; // zobrazi znak
		if (line[i] == '.') 				// ukonèení, když je teèka
			break;
		if (line[i] != ' ') 				// pøeskoèení zbytku pøíkazù v cyklu
			continue;
		spaces++;
	}
	cout << "\n" << spaces << " mezer\n";
	cout << "Konec.\n";
	
	char ch;
	cin.get(ch);
	while (ch != '@')
	{
	 	 cin.get(ch);
    }
	
	return 0;
}
