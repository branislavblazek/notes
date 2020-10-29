// textin3.cpp -- ètení znakù do konce souboru
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cin.get(ch); 								// pokus pøeèíst znak
	while (cin.eof() == false) 		// test na EOF
	{
		cout << ch; 							// echo znaku na displeji
		++count;
		cin.get(ch); 							// pokus o ètení dalšího znaku
	}
	cout << endl << count << " znaku nacteno\n";
	
	return 0;
}
