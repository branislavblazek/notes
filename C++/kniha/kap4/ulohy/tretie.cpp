#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 80;
int main()
{
	char meno[SIZE];
	char priezvisko[SIZE];
	char full[2*SIZE+1];
	
	cout << "Zadajte vase meno:" << endl;
	cin.getline(meno, SIZE);
	cout << "Zadajte vase priezvisko:" << endl;
	cin.getline(priezvisko, SIZE);
	strncpy(full, priezvisko, SIZE);
	strcat(full, ", ");
	strncat(full, meno, SIZE);
	full[SIZE-1] = '\0';
	cout << full;
	
	return 0;
}
