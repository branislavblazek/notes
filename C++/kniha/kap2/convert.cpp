#include <iostream>
using namespace std;

int stonetolib(int);

int main(void)
{
	int stone;
	cout << "Zadajte vahu v kamenoch: ";
	cin >> stone;
	int pounds = stonetolib(stone);
	cout << stone << " kamenov je " << pounds << " libier" << endl;
	
	return 0;
}

int stonetolib(int stone)
{
	return 14 * stone;
}
