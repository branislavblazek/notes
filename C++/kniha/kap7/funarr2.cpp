#include <iostream>
const int ArSize = 8;
int sum_array(int arr[], int n);

int main()
{
	int n = 5;
	std::cout << sizeof n << std::endl;
	int cookies[8] = {2,4,6,8,16,32,64,128};
	
	std::cout << cookies << " = adresa pola, ";
	std::cout << sizeof cookies << " = velkost cookies\n";
	int sum = sum_array(cookies, ArSize);
	std::cout << "celkovy pocet " << sum << std::endl;
	sum = sum_array(cookies, 3);
	std::cout << "Prvy traja zjedli " << sum << std::endl;
	sum = sum_array(cookies + 4, 4);
	std::cout << "Posledny styria zjedli " << sum << std::endl;
	return 0;
}

int sum_array(int arr[], int n)
{
	int total;
	std::cout << arr << " = arr, ";
	std::cout << sizeof arr << " = velkost arr\n";
	for (int i = 0; i < n; i++)
	{
		total += arr[i];
	}
	return total;
}
