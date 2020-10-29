#include <iostream>
using namespace std;

int main() {
	int pocet_cisel;
	cin >> pocet_cisel;
	if (pocet_cisel == 1){
		int vstup;
		cin >> vstup;
		if (vstup < 0){
			cout << "zaporrrne" << endl;
		}
		else{
			cout << "nezaporrrne" << endl;
		}
	}
	else if (pocet_cisel == 2){
		int a, b;
		cin >> a >> b;
		cout << b << " " << a << endl;
		if (a == b){
			cout << "To bolo lahke." << endl;
		}
	} else {
		int a, b, c;
		cin >> a >> b >> c;
		if (a <= b){
			if (a <= c){
				cout << a << endl;
				return 0; 
			}
		}
		if (b <= c){
			if (b <= a){
				cout << b << endl;
				return 0;
			}
		}
		if (c <= a){
			if (c <= b){
				cout << c << endl;
				return 0;
			}
		}
	}
}
