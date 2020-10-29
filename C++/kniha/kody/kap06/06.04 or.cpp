// or.cpp -- použití logického operátoru NEBO (OR)
#include <iostream>
int main()
{
	using namespace std;
	cout << "Tento program muze preformatovat vas pevny disk\n"
					"a zrusit vsechna vase data.\n"
					"Prejete si pokracovat? <a/n> ";
	char ch;
	cin >> ch;
	if (ch == 'a' || ch == 'A') 							// a nebo A
		cout << "Byl jste upozornen!\a\a\n";
	else if (ch == 'n' || ch == 'N') 					// n nebo N
		cout << "Moudra volba ... sbohem\n";
	else
		cout << "Nebylo zadano ani a ani n, tak myslim,\n"
						"ze vas disk v kazdem pripade znicim.\a\a\a\n";
	
	return 0;
}
