#include <iostream>
using namespace std;

int main(){
	int ludi, pocet = 0, min = 10001;
	cin >> ludi;
	for (int i = 0; i < ludi; i++){
		int plat;
		cin >> plat;
		if (plat < min){
			min = plat;
			pocet = 1;
		}	
		else if (plat == min){
			pocet++;
		}
	}
	cout << pocet << endl;
}
