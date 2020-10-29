// block.cpp -- pouití pøíkazù v bloku
#include <iostream>
int main()
{
	using namespace std;
	cout << "Bajecny Accounto vam secte";
	cout << " a vypocita prumer z peti cisel.\n";
	cout << "Prosim, zadejte pet hodnot:\n";
	double number;
	double sum = 0.0;
	for (int i = 1; i <= 5; i++)
	{ 															// zaèátek bloku
		cout << "Hodnota " << i << ": ";
		cin >> number;
		sum += number;
	} 															// konec bloku
	cout << "Vybral jste pet opravdu skvelych cisel! ";
	cout << "Jejich soucet je " << sum << endl;
	cout << "a prumer " << sum / 5 << ".\n";
	cout << "Bajecny Accounto se s vami louci!\n";
	
	return 0;
}
