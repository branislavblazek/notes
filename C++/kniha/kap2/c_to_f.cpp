#include <iostream>
using namespace std;
int c_to_f(int);

int main(void)
{
	int c_temp;
	cout << "Zadajte teplotu v stupnoch Celzia: ";
	cin >> c_temp;
	int f_temp;
	f_temp = c_to_f(c_temp);
	cout << c_temp << "C je " << f_temp << "F." << endl;
}

int c_to_f(int c)
{
	return 1.8 * c + 32;
}
