#include <iostream>
using namespace std;

int main(){
	long long zaciatok, max, a, b, c;
	// nacita zaciatocnuu hodnotu a pocet kolko mam dat vysledkov
	cin >> zaciatok >> max;
	// nacita formicky
	cin >> a >> b >> c;
	long long root_a, root_b, root_c;
	root_a = zaciatok / a * a;
	root_b = zaciatok / b * b;
	root_c = zaciatok / c * c;
	long long pocet = 0;
	if (root_a == zaciatok || root_b == zaciatok || root_c == zaciatok){
		cout << zaciatok << " ";
		pocet++;
	}
	while (pocet < max){
		// tu bude ulozene najmensie hodnota
		long long najmensi = false, x;
		if (najmensi == false && root_a + a > zaciatok){
			najmensi = root_a + a;
			x = a;
		}
		// prejdi hodnoty okrem a-cka a nastav podla toho najmensi
		if (root_b + b < najmensi && root_b + b > zaciatok){
			najmensi = root_b + b;
			x = b;
		}
		if (root_c + c < najmensi && root_c + c > zaciatok){
			najmensi = root_c + c;
			x = c;
		}
		//pokial si nic nezisitil
		if (najmensi == false){
			pocet++;
			continue;
		}
		//zisti hodnotu o ktore sa zmeni zaciatok
		zaciatok = najmensi;
		pocet++;
		cout << zaciatok;
		if (zaciatok == 6660){
			cout << zaciatok << " " << a << " " << b << " " << c << endl;
		}
		if (pocet != max){
			cout << " ";
		}
		// zisti kde, ku ktoremu root mas pripocitat hodnotu
		if (root_a + a == zaciatok){
			root_a += a;
		}
		if (root_b + b == zaciatok){
			root_b += b;
		}
		if (root_c + c == zaciatok){
			root_c += c;
		}
	}
	cout << endl;
}
