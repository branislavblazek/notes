#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int hod, min;
	cin >> hod >> min;
	if (hod >= 2 && hod <= 4){
		cout << "Su " << hod;
	} else{
		cout << "Je " << hod;
	}
	if (hod == 1){
		cout << " hodina a " << min;
	} else if (hod >= 2 && hod <= 4){
		cout << " hodiny a " << min;
	} else {
		cout << " hodin a " << min;
	}
	if (min == 1){
		cout << " minuta." << endl;
	} else if (min >= 2 && min <= 4){
		cout << " minuty." << endl;
	} else {
		cout << " minut." << endl;
	}
}
