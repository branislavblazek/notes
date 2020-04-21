// if.cpp -- použití pøíkazu if
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int spaces = 0;
	int total = 0;
	cin.get(ch);
	while (ch != '.') 		// ukonèení na konci vìty
	{
		if (ch == ' ') 		// test, zda je ch mezera
			++spaces;
		++total; 					// provádí se pokaždé
		cin.get(ch);
	}
	cout << spaces << " mezer, " << total;
	cout << " znaku celkem ve vete\n";
	
	return 0;
}
