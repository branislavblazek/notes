// compstr.cpp -- porovnání øetìzcù
#include <iostream>
#include <cstring> // prototyp pro strcmp()
int main()
{
	using namespace std;
	char word[5] = "?ate";

	for (char ch = 'a'; strcmp(word, "mate"); ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	cout << "Po skonceni cyklu je slovo " << word << endl;
	
	return 0;
}
