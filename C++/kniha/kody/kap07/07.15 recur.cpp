// recur.cpp -- použití rekurze
#include <iostream>
void countdown(int n);

int main()
{
	countdown(4); 					// volá rekurzivní funkci
	return 0;
}

void countdown(int n)
{
	using namespace std;
	cout << "Odpocitavani ... " << n << "\n";
	if (n > 0)
		countdown(n - 1); 		// funkce volá sama sebe
cout << n << ": Kaboom!\n";
}
