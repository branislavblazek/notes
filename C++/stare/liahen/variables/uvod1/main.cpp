#include <iostream>
using namespace std;


int main() {
	int pocet_kociek, horne_cislo, dolne_cislo;
	cin >> pocet_kociek >> horne_cislo;
	dolne_cislo = 7 - horne_cislo;
	cout << pocet_kociek * horne_cislo + pocet_kociek * dolne_cislo - horne_cislo << endl;
	return 0;
}
