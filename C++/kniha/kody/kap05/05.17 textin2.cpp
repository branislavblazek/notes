//textin2.cpp -- použití funkce cin.get(char)
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;

	cout << "Zadejte znaky; zadejte # pro ukonceni:\n";
	cin.get(ch); 				// použijte funkci cin.get(ch)
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch); 			// použijte ji znovu
	}
	cout << endl << count << " znaku nacteno\n";
	
	return 0;
}
