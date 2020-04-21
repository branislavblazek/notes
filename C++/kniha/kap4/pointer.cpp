#include <iostream>
using namespace std;

int main()
{
	int updates = 6;
	int * p_updates;
	
	p_updates = &updates;
	
	cout << "Hodnoty: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;
	
	cout << "Adresy: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;
}
