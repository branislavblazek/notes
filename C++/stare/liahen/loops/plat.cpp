#include <iostream>
using namespace std;

int main(){
	int pocet, max = 0;
	cin >> pocet;
	for (int i = 0; i < pocet; i++){
		int plat;
		cin >> plat;
		if (plat > max){
			max = plat;
		}
	}
	cout << max << endl;
}
