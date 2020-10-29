// forstr2.cpp -- obrácení pole
#include <iostream>
#include <cstring>
const int ArSize = 20;
int main()
{
	using namespace std;
	cout << "Zadejte slovo: ";
	string word;
	cin >> word;

	// fyzicky modifikuje pole
	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
	{ 												// zaèátek bloku
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	} 												// konec bloku
	cout << word << "\nKonec\n";
	
	return 0;
}
