// leftover.cpp -- pøetížení funkce left()
#include <iostream>
unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n = 1);
int main()
{
	using namespace std;
	char * trip = "Havaj!!!"; 			// testovací hodnota
	unsigned long n = 12345678; 			// testovací hodnota
	int i;
	char * temp;

	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete [] temp; 							// ukazuje na doèasnou pamì
	}
	return 0;

}

// Tato funkce vrací ct prvních èíslic z èísla num.
unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0)
		return 0; 									// vrací 0, když nejsou èíslice
	while (n /= 10)
		digits++;
	if (digits > ct)
	{
	ct = digits - ct;
	while (ct--)
		num /= 10;
	return num; 									// vrací ct èíslic zleva
	}
	else // jestliže ct >= poèet èíslic
		return num; 								// vrací celé èíslo
}

// Tato funkce vrací ukazatel na øetìzec, který obsahuje
// prvních n znakù v øetìzci str.
char * left(const char * str, int n)
{
	if (n < 0)
		n = 0;
	char * p = new char[n+1];
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i]; 							// kopírování znakù
	while (i <= n)
		p[i++] = '\0'; 							// nastaví zbytek øetìzce na '\0'
	return p;
}
