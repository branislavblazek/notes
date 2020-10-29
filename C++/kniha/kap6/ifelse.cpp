#include <iostream>
using namespace std;

int main()
{
	char ch;
	cout << "Zadajte nejaku krasnu vetu" << endl;
	
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
			cout << ch;
		else 
			cout << ++ch;
		cin.get(ch);
	}
	cout << "Co sa to tu deje? Ja by som tie internety zakazal!" << endl;
	return 0;
}
