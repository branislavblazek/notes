// vslice.cpp -- použití valarray slices
#include <iostream>
#include <valarray>
#include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint; // zjednodušení deklarace
void show(const vint & v, int cols);

int main()
{
	using std::slice; // z <valarray>
	using std::cout;
	vint valint(SIZE); // pøedstav si 4 øádky po 3

	int i;
	for (i = 0; i < SIZE; ++i)
		valint[i] = std::rand() % 10;
	cout << "Puvodni pole:\n";
	show(valint, 3); // ukaž ve 3 sloupcích
	vint vcol(valint[slice(1,4,3)]); // extrahuj 2. sloupec
	cout << "Druhy sloupec:\n";
	show(vcol, 1); // show in 1 column
	vint vrow(valint[slice(3,3,1)]); // extrahuj 2. øádek
	cout << "Druhy radek:\n";
	show(vrow, 3);
	valint[slice(2,4,3)] = 10; // pøiøaï 2. sloupci
	cout << "Nastav poslední sloupec na 10:\n";
	show(valint, 3);
	cout << "Nastav prvni sloupec na soucet dalsich dvou:\n";
	// + není definováno pro slices, pøeveï tedy do valarray<int>
	valint[slice(0,4,3)] = vint(valint[slice(1,4,3)])
													+ vint(valint[slice(2,4,3)]);
	show(valint, 3);
	return 0;
}

void show(const vint & v, int cols)
{
	using std::cout;
	using std::endl;

	int lim = v.size();
	for (int i = 0; i < lim; ++i)
	{
		cout.width(3);
		cout << v[i];
		if (i % cols == cols - 1)
			cout << endl;
	else
			cout << ' ';
	}
	if (lim % cols != 0)
		cout << endl;
}
