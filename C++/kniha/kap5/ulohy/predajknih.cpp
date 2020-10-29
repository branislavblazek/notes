#include <iostream>
using namespace std;

int main()
{
	const char * mesiace[12] = 
	{
		"januar",
		"februar",
		"marec",
		"april",
		"maj",
		"jun",
		"jul",
		"august",
		"september",
		"oktober",
		"november",
		"december"
	};
	
	int predaj[12];
	
	for (int i = 0; i < 12; i++)
	{
		cout << "Zadajte pocet predanych knih za mesiac " << mesiace[i] << ": ";
		int pocet;
		cin >> pocet;
		predaj[i] = pocet;
	};
	for (int i = 0; i < 12; i++)
	{
		cout << "Za mesiac " << mesiace[i] << " to bolo " << predaj[i] << endl;
	};
	return 0;
}
