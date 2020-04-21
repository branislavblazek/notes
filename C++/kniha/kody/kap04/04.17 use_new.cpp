// use_new.cpp -- použití operátoru new
#include <iostream>
int main()
{
	using namespace std;
	int * pt = new int; 							// alokuje prostor pro int
	*pt = 1001; 										// uloží tam hodnotu

	cout << "int ";
	cout << "hodnota = " << *pt << ": umisteni = " << pt << endl;

	double * pd = new double; 				// alokuje prostor pro double
	*pd = 10000001.0; 								// uloží tam double

	cout << "double ";
	cout << "hodnota = " << *pd << ": umisteni = " << pd << endl;
	cout << "velikost pt = " << sizeof pt;
	cout << ": velikost *pt = " << sizeof *pt << endl;
	cout << "velikost pd = " << sizeof pd;
	cout << ": velikost *pd = " << sizeof *pd << endl;
	
	return 0;
}
