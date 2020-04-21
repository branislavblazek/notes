// express.cpp -- hodnoty výrazù
#include <iostream>
int main()
{
	using namespace std;
	int x;

	cout << "Vyraz x = 100 ma hodnotu ";
	cout << (x = 100) <<  endl;
	cout << "Nyni je x = " << x <<  endl;
	cout << "Vyraz x < 3 ma hodnotu ";
	cout << (x < 3) <<  endl;
	cout << "Vyraz x > 3 ma hodnotu ";
	cout << (x > 3) <<  endl;
	cout.setf(ios_base::boolalpha);
	cout << "Vyraz x < 3 ma hodnotu ";
	cout << (x < 3) <<  endl;
	cout << "Vyraz x > 3 ma hodnotu ";
	cout << (x > 3) <<  endl;
	
	return 0;
}
