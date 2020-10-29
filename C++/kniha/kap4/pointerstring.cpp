#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char animal[20] = "medved";
	const char * bird = "strizlik"; //bird obsahuje adresu retazca
	char * ps;
	
	cout << animal << " a " << bird << endl;
	
	cout << "Zadajte druh zvierata: " << endl;
	cin >> animal;
	
	ps = animal; //ps ukazuje na retazec
	cout << ps << endl;
	cout << "Pred pouzitim strcpy()" << endl;
	cout << animal << " je na adrese " << (int *)animal << endl;
	cout << ps << " je na adrese " << (int *) ps << endl;
	
	ps = new char[strlen(animal) + 1]; //ziska novu pamat
	strcpy(ps, animal); //kopiruje retazec do novej pamati
	cout << "po pouziti strcpy()" << endl;
	cout << animal << " je na adrese " << (int *)animal << endl;
	cout << ps << " je na adrese " << (int *) ps << endl;
	delete [] ps;
	
	return 0;
	
}
