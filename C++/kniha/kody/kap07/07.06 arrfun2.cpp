// arrfun2.cpp -- funkce s argumentem typu pole
#include <iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);
// místo direktivy using použijeme std::
int main()
{
	int cookies[ArSize] = {1,2,4,8,16,32,64,128};
// nìkteré systémy vyžadují, aby bylo
// pøi inicializaci pole pøed int vloženo static

	std::cout << cookies << " = adresa pole, ";
// nìkteré systémy vyžadují pøetypování: unsigned (cookies)

	std::cout << sizeof cookies << " = velikost cookies\n";
	int sum = sum_arr(cookies, ArSize);
	std::cout << "Celkovy pocet snedenych zakusku: " << sum << std::endl;
	sum = sum_arr(cookies, 3); 						// lež
	std::cout << "Prvni tri jedlici snedli " << sum << " zakusku.\n";
	sum = sum_arr(cookies + 4, 4); 				// další lež
	std::cout << "Posledni ctyri jedlici snedli " << sum << " zakusku.\n";
	return 0;
}

// vrací souèet prvkù celoèíselného pole
int sum_arr(int arr[], int n)
{
	int total = 0;
	std::cout << arr << " = arr, ";
// nìkteré systémy vyžadují pøetypování: unsigned (arr)

	std::cout << sizeof arr << " = velikost arr\n";
	for (int i = 0; i < n; i++)
		total = total + arr[i];
	return total;
}
