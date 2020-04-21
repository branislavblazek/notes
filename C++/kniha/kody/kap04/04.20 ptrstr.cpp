// ptrstr.cpp -- použití ukazatelù na øetìzce
#include <iostream>
#include <cstring> // deklaruje strlen(), strcpy()
int main()
{
	using namespace std;
	char animal[20] = "medved"; 			// animal obsahuje medved
	const char * bird = "strizlik"; 	// bird obsahuje adresu øetìzce
	char * ps; 										// neinicializováno

	cout << animal << " a "; 	// zobrazí medved
	cout << bird << "\n"; 		// zobrazí strizlik
	// cout << ps << "\n";		// mùže zobrazit nesmysl nebo zpùsobit pád programu

	cout << "Zadejte druh zvirete: ";
	cin >> animal; 						// v poøádku pokud je vstup kratší než 20 znakù
	// cin >> ps; Velmi hrubá chyba;
	// ps neukazuje na alokovaný prostor

	ps = animal; 						// nastaví ps, aby ukazoval na øetìzec
	cout << ps << "!\n"; 			// v poøádku, stejné jako použití animal
	cout << "Pred pouzitim strcpy():\n";
	cout << animal << " je na adrese " << (int *) animal << endl;
	cout << ps << " je na adrese " << (int *) ps << endl;

	ps = new char[strlen(animal) + 1]; // získá novou pamì
	strcpy(ps, animal); // kopíruje øetìzec do nové pamìti
	cout << "Po pouziti strcpy():\n";
	cout << animal << " je na adrese " << (int *) animal << endl;
	cout << ps << " je na adrese " << (int *) ps << endl;
	delete [] ps;
	
	return 0;
}
