#include <iostream>
using namespace std;

int main(void)
{
	char ch = 'M';
	int i = ch;
	cout << "ASCII kod pre " << ch << " je " << i << endl;
	
	cout << "Ku kodu pripocitam jedna." << endl;
	ch = ch + 1;
	i = ch;
	cout << "ASCII kod pre " << ch << " je " << i << endl;
	
	cout.put(ch);
	cout.put('!');
	
	cout << endl << "Hotovo!" << endl;
	return 0;
}
