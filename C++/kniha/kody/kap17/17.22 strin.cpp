// strin.cpp -- formátované ètení ze znakového pole
#include <iostream>
#include <sstream>
#include <string>
int main()
{
	using namespace std;
	string lit = "Byl tmavy a bourlivy den a "
							" jasne zaril uplnek. ";
	istringstream instr(lit); 	// použití vyrovnávací pamìti pro vstup
	string word;;
	while (instr >> word) 			// ètení po slovech
		cout << word << endl;

	return 0;
}
