// cctypes.cpp -- použití knihovny ctype.h
#include <iostream>
#include <cctype> // prototypy znakových funkcí
int main()
{
	using namespace std;
	cout << "Zadejte text pro analyzu a znakem @"
				" ukoncete vstup.\n";
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch); 									// získá první znak
	while(ch != '@') 							// test ukonèení vstupu
	{
		if(isalpha(ch)) 							// je to alfabetický znak?
			chars++;
		else if(isspace(ch)) 					// je to bílý znak?
			whitespace++;
		else if(isdigit(ch)) 					// je to èíslice?
			digits++;
		else if(ispunct(ch)) 					// je to znak interpunkce?
			punct++;
		else
			others++;
		cin.get(ch); // získá další znak
	}
	cout << chars << " pismen, "
			<< whitespace << " bilych znaku, "
			<< digits << " cislic, "
			<< punct << " interpunkcnich znaku, "
			<< others << " ostatnich.\n";
			
				cin.get(ch); 									// získá první znak
					while(ch != '@') 							// test ukonèení vstupu
                    {
                    cin.get(ch); // získá další znak
                    }       
	return 0;
}
