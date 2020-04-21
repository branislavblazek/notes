// copy.cpp -- funkce copy() a iterátory
#include <iostream>
#include <iterator>
#include <vector>
int main()
{
	using namespace std;

	int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
	vector<int> dice(10);
	// kopírování z pole do vektoru
	copy(casts, casts + 10, dice.begin());
	cout << "Hodte kostky!\n";
	// vytvoøí iterátor ostream
	ostream_iterator<int, char> out_iter(cout, " ");
	// kopírování z vektoru na výstup
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout <<"Implicitni pouziti inverzniho iteratoru.\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout <<"Explicitni pouziti inverzniho iteratoru.\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
	cout << *ri << ' ';
	cout << endl;

	return 0;
}
