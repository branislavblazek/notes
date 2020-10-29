#include <iostream>
using namespace std;

int main(){
	char pismeno;
	int pismeno_index;
	int cislo;
	cin >> pismeno >> cislo;
	pismeno_index = pismeno - 64;
	cout << 8 * (8-cislo) + pismeno_index << endl;
}
