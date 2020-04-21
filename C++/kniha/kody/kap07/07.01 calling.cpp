// calling.cpp -- definování, vytvoøení prototypu a volání funkce
#include <iostream>

void simple(); 				// prototyp funkce

int main()
{
	using namespace std;
	cout << "main() bude volat funkci simple():\n";
	simple(); 					// volání funkce
	int xxx;
}

// definice funkce
void simple()
{
	using namespace std;
	cout << "Jsem to ale jednoducha funkce.\n";
}
