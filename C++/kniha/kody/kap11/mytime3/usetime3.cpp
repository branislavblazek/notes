// usetime3.cpp -- použití ètvrtého návrhu tøídy Time
// spoleèná kompilace souborù usetime3.cpp a mytime3.cpp
#include <iostream>
#include "mytime3.h"
int main()
{
	using std::cout;
	using std::endl;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida a Tosca:\n";
	cout << aida<<"; " << tosca << endl;
	temp = aida + tosca; 										// operátor+()
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida* 1.17; 										// èlenský operátor*()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10 * Tosca: " << 10 * tosca << endl;

	return 0;
}
