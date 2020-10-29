// divide.cpp -- deleni celociselne a v poh. des. carce
#include <iostream>
int main()
{

	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Celociselne deleni: 9/5 = " << 9 / 5 << endl;
	cout << "Deleni v poh. des. carce: 9.0/5.0 = ";
	cout << 9.0 / 5.0 << endl;
	cout << "Kombinovane deleni: 9.0/5 = " << 9.0 / 5 << endl;
	cout << "konstanty typu double: 1e7/9.0 = ";
	cout << 1.e7 / 9.0 << endl;
	cout << "konstanty typu float: 1e7f/9.0f = ";
	cout << 1.e7f / 9.0f << endl;
	
	return 0;
}
