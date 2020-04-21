// arrfun4.cpp -- funkce s rozsahem pole
#include <iostream>
const int ArSize = 8;
int sum_arr(const int * begin, const int * end);
int main()
{
	using namespace std;
	int cookies[ArSize] = {1,2,4,8,16,32,64,128};
// nìkteré systémy vyžadují, aby bylo
// pøi inicializaci pole pøed int vloženo static

	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "Celkovy pocet snedenych zakusku: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3); 						// první 3 prvky
	cout << "Prvni tri jedlici snedli " << sum << " zakusku.\n";
	sum = sum_arr(cookies + 4, cookies + 8); 				// poslední 4 prvky
	cout << "Posledni ctyri jedlici snedli " << sum << " zakusku.\n";
	return 0;
}

// vrací souèet prvkù celoèíselného pole
int sum_arr(const int * begin, const int * end)
{
	const int * pt;
	int total = 0;

	for (pt = begin; pt != end; pt++)
		total = total + *pt;
	return total;
}
