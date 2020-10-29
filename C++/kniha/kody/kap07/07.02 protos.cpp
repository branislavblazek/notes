// protos.cpp -- použití prototypù a volání funkcí
#include <iostream>
void cheers(int); 							// prototyp: žádná návratová hodnota
double cube(double x); 					// prototyp: vrací hodnotu typu double
int main(void)
{
	using namespace std;
	cheers(5); 									// volání funkce
	cout << "Zadejte cislo: ";
	double side;
	cin >> side;
	double volume = cube(side); 		// volání funkce
	cout << "Krychle o velikosti strany " << side <<" metru ma objem ";
	cout << volume << " metru krychlovych.\n";
	cheers(cube(2)); 						// ukázka prototypové ochrany
	return 0;
}

void cheers(int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << "Slava! ";
	cout << "\n";
}
double cube(double x)
{
	return x * x * x;
}
