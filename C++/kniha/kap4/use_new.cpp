#include <iostream>
using namespace std;

int main()
{
	int * pntr = new int; //alokuje priestor pre int
	*pntr = 1001; //ulozi tam hodnotu
	
	cout << "int hodnota = " << *pntr << ": umiestnenie = " << pntr << endl;
	
	double * pdouble = new double;
	*pdouble = 1234.56;
	
	cout << "double hodnota = " << *pdouble << ": umiestnenie = " << pdouble << endl;
	
	cout << "velkost pntr = " << sizeof pntr;
	cout << ": velkost *pntr = " << sizeof *pntr << endl;
	 
	cout << "velkost pdouble = " << sizeof pdouble;
	cout << ": velkost *pdouble = " << sizeof *pdouble << endl;
	
	return 0;
}
