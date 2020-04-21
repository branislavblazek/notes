// left.cpp -- øetìzcová funkce s implicitním argumentem
#include <iostream>
const int ArSize = 80;
char * left(const char * str, int n = 1);
int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "Zadejte retezec:\n";
	cin.get(sample, ArSize);
	char *ps = left(sample, 4);
	cout << ps << "\n";
	delete [] ps; 			// uvolnìní starého øetìzce
	ps = left(sample);
	cout << ps << endl;
	delete [] ps; 			// uvolnìní nového øetìzce
	return 0;
}

// Tato funkce vrací ukazatel na nový øetìzec, který
// obsahuje prvních n znakù øetìzce str.
char * left(const char * str, int n)
{
	if(n < 0)
		n = 0;
	char * p = new char[n+1];
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i]; // kopírování znakù
	while (i <= n)
		p[i++] = '\0'; // zbytek se nastaví na '\0'
	return p;
}
