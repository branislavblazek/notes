// textin4.cpp -- ètení znakù pomocí cin.get()
#include <iostream>
int main(void)
{
	using namespace std;
	int ch; 											// mìlo by být int, ne char
	int count = 0;

	while ((ch = cin.get()) != EOF) 	// test na konec souboru
	{
		cout.put(char(ch));
		++count;
	}
	cout << endl << count << " znaku nacteno\n";
	
	return 0;
}
