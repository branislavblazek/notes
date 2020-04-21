// convert.cpp -- konvertuje kameny na libry
#include <iostream>
int stonetolb(int); 		// funkèní prototyp
int main()
{
	using namespace std;
	int stone;
	cout << "Zadejte vahu v kamenech: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " kamenu je ";
	cout << pounds << " liber." << endl;
	return 0;
}

int stonetolb(int sts)
{
	return 14 * sts;
}
