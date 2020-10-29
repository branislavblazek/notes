// strgfun.cpp -- funkce s øetìzcovým argumentem
#include <iostream>
int c_in_str(const char * str, char ch);
int main()
{
	using namespace std;
	char mmm[15] = "minimum"; 		// øetìzec v poli
// nìkteré systémy vyžadují, aby bylo
// pøi inicializaci pole pøed int vloženo static

	char *wail = "narikat"; 			// promìnná wail (skuèet) ukazuje na øetìzec

	int ms = c_in_str(mmm, 'm');
	int as = c_in_str(wail, 'a');
	cout << ms << " znaky m v retezci " << mmm << endl;
	cout << as << " znaky a v retezci " << wail << endl;
	return 0;
}

// tato funkce poèítá poèet znakù ch
// v øetìzci str
int c_in_str(const char * str, char ch)
{
	int count = 0;

	while (*str) 				// konec, když je *str rovno '\0'
	{
		if (*str == ch)
			count++;
		str++; 						// pøesun ukazatele na další znak
	}
	return count;
}
