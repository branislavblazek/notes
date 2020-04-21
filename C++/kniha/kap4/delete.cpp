#include <iostream>
#include <cstring>
using namespace std;

char * getname(void);//prototyp

int main()
{
	char * name; //nealokuje pamat
	name = getname(); //priradi adresu retazca do name
	cout << name << " na adrese " << (int *) name << endl;
	delete [] name;
	
	name = getname(); //nove pouzitie uvolnenej pamate
	cout << name << " na adrese " << (int *)name << endl;
	delete [] name;
	return 0;
}

char * getname(void) //vracia pointer
{
	char temp[80]; //docasna pamat
	cout << "zadajte priezvisko: ";
	cin >> temp;
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp); //kopiruje retazec do mensieho priestoru
	
	return pn; //temp sa strati
}
