#include <iostream>
using namespace std;

int main()
{
	char ch;
	int count = 0;
	cout << "Zadajte znaky, zadajte # pre ukoncenie" << endl;
	cin.get(ch);
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " znakov nacitanych" << endl;
	return 0;
}
