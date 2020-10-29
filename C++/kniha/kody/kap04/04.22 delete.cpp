// delete.cpp -- pouití operátoru delete
#include <iostream>
#include <cstring> 			// nebo string.h
using namespace std;
char * getname(void); 		// funkèní prototyp
int main()
{
	char * name; 					// vytváøí ukazatel, ale nealokuje pamì

	name = getname(); 			// pøiøazuje adresu øetìzce do name
	cout << name << " na adrese " << (int *) name << "\n";
	delete [] name; 				// uvolnil pamì

	name = getname(); 			// nové pouití uvolnìné pamìti
	cout << name << " na adrese " << (int *) name << "\n";
	delete [] name; 				// opìt uvolnil pamì
	return 0;
}

char * getname() 				// vrací ukazatel novému øetìzci
{
	char temp[80]; 				// doèasná pamì
	cout << "Zadejte prijmeni: ";
	cin >> temp;
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp); 			// kopíruje øetìzec do menšího prostoru

	return pn; 						// temp se ztrácí, kdy funkce konèí
}
