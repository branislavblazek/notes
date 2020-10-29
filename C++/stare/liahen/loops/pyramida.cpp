#include <iostream>
using namespace std;

int main(){
	int pocet;
	cin >> pocet;
	for (int i = 0; i < pocet; i++){
		int pocet_medzier = pocet - i - 1;
		int pocet_hviezd = 2*i+1;
		for (int j = 0; j < pocet_medzier; j++){
			cout << " ";
		}
		for (int k = 0; k < pocet_hviezd; k++){
			cout << "*";
		}
		for (int j = 0; j < pocet_medzier; j++){
			cout << " ";
		}
		cout << endl;
	}
}
