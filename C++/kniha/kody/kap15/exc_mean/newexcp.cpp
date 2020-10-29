// newexcp.cpp -- výjimka bad_alloc
#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

struct Big
{
	double stuff[20000];
};

int main()
{
	Big * pb;
	try {
		cout << "Zkousim pozadat o velky blok pameti:\n";
		pb = new Big[10000]; // 1,600,000,000 bytes
		cout << "Ted jsem za prikazem new:\n";
	}
	catch (bad_alloc & ba)
	{
		cout << "Zachycena vyjimka!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	if (pb != 0)
	{
		pb[0].stuff[0] = 4;
		cout << pb[0].stuff[0] << endl;
	}
	else
		cout << "pb je nulovy ukazatel\n";
	delete [] pb;
	return 0;
}
