// ourfunc.cpp -- definování vlastní funkce
#include <iostream>
void simon(int); 			// funkèní prototyp pro simon()

int main()
{
	using namespace std;
	simon(3); 					// volání funkce simon()
	cout << "Vyberte si cele cislo: ";
	int count;
	cin >> count;
	simon(count); 				// opìtovné volání
	cout << "Hotovo!" << endl;
	return 0;
}

void simon(int n) 			// definice funkce simon()
{
	using namespace std;
	cout << "Simon rika, abyste se dotknul prstu u nohou " << n << " krat. " 
	<< endl;
} 										// funkce void nemusí být ukonèeny pøíkazem return
