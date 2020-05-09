#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	cout << "Zadajte oneskorenie: " << endl;
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;
	cout << "Zaciatok\a\n";
	clock_t start = clock();
	while (clock() - start < delay);
	cout << "koniec\a\n" << endl;
	return 0;
}
