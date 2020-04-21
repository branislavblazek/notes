// check_it.cpp -- ovìøení platného vstupu
#include <iostream>

int main()
{
	using namespace std;
	cout << "Zadavejte cisla: ";

	int sum = 0;
	int input;
	while (cin >> input)
	{
		sum += input;
	}

	cout << "Posledni zadana hodnota = " << input << endl;
	cout << "Soucet = " << sum << endl;

	return 0;
}
