// textin1.cpp -- ètení znakù cyklem while
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0; 					// použije základní vstup
	cout << " Zadejte znaky; zadejte # pro ukonceni:\n";
	cin >> ch; 							// získá znak
	while (ch != '#') 				// test znaku
	{
		cout << ch; 					// zobrazení znaku
		++count; 							// pøiètení znaku
		cin >> ch; 						// získá další znak
	}
	cout << endl << count << " znaku nacteno\n";
	
	return 0;
}
