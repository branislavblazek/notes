#include <iostream>
using namespace std;

int main()
{
	double wages[3] = {100.0, 200.0, 300.0};
	short stacks[3] = {1, 2, 3};
	
	//su dva sposoby ziskania adresy polia
	double *p_wages = wages; //meno pola == adresa
	short *p_stacks = &stacks[0]; //pouzitie adresoveho operatoru s prvkom pola
	
	cout << "p_wages = " << p_wages << ", *p_wages = " << *p_wages << endl;
	p_wages = p_wages + 1;
	cout << "k pointru pripocitame jedna." << endl;
	cout << "p_wages = " << p_wages << ", *p_wages = " << *p_wages << endl << endl;
	
	cout << "p_stacks = " << p_stacks << ", *p_stacks = " << *p_stacks << endl;
	p_stacks = p_stacks + 1;
	cout << "k pointru pripocitame jedna." << endl;
	cout << "p_stacks = " << p_stacks << ", *p_stacks = " << *p_stacks << endl << endl;
	
	cout << "Spristupnenie dvoch prvkov pomocou zapisu polia";
	cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
	cout << "Spristupnenie dvoch prvkov pomocou zapisu pointra";
	cout << "*stacks = " << *stacks << ", *(stacks+1)" << *(stacks+1) << endl;
	
	cout << sizeof wages << " = velkost pola wages." << endl;
	cout << sizeof stacks << " = velkost polia stacks." << endl;
	
	return 0; 
}
