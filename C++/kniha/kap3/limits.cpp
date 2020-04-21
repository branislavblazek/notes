#include <iostream>
#include <climits>
using namespace std;

int main(void)
{
	int n_int = INT_MAX;
	unsigned u_int = UINT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	unsigned long u_long = ULONG_MAX;
	
	
	cout << "Maximalne hodnoty" << endl;
	cout << "int: " << n_int << endl;
	cout << "unsigned int: " << u_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "unsigned long: " << u_long << endl;
	
	return 0;
}
