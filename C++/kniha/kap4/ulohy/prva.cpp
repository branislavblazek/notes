#include <iostream>
using namespace std;

int main()
{
	char meno[80];
	char prv[80];
	int vek;
	cout << "Ake je vase krstne meno? ";
	cin.getline(meno, 80);
	cout << "Ake je vase priezvisko? ";
	cin.getline(prv, 80);
	cout << "Kolko je vam rokov? ";
	cin >> vek;
	cout << endl;
	cout << "Meno: " << prv << ", " << meno << endl;
	cout << "Vek: " << vek;
	
	return 0;
}
