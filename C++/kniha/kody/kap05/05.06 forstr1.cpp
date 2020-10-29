// forstr1.cpp -- použití cyklu for s øetìzcem
#include <iostream>
#include <cstring>
const int ArSize = 20;
int main()
{
	using namespace std;
	cout << "Zadejte slovo: ";
	string word;
	cin >> word;

	// zobrazuje písmena v opaèném poøadí
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << "\nNashledanou.\n";
	
	return 0;
}
