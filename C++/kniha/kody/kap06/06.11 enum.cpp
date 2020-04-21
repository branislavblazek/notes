// enum.cpp -- použití enum
#include <iostream>
// vytvoøení pojmenovaných konstant pro 0 - 6
enum {cervene, oranzove, zlute, zelene, modre, fialove, ruzovou};

int main()
{
	using namespace std;
	cout << "Zadejte kod barvy (0-6): ";
	int code;
	cin >> code;
	while (code >= cervene && code <= ruzovou)
	{
		switch (code)
		{
			case cervene 	: cout << "Mela cervene rty.\n"; break;
			case oranzove	: cout << "Mela oranzove vlasy.\n"; break;
			case zlute 		: cout << "Mela zlute boty.\n"; break;
			case zelene 	: cout << "Mela zelene nehty.\n"; break;
			case modre 		: cout << "Mela modre teplaky.\n"; break;
			case fialove 	: cout << "Mela fialove oci.\n"; break;
			case ruzovou	: cout << "Mela ruzovou naladu.\n"; break;
		}
		cout << "Zadejte kod barvy (0-6): ";
		cin >> code;
	}
	cout << "Sbohem\n";
	
	return 0;
}
