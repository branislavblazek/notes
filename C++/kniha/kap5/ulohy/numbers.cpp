#include <iostream>
using namespace std;

int main()
{
	int vstup;
	int count = 0;
	cin >> vstup;
	while (vstup != 0)
	{
		count += vstup;
		cin >> vstup;
	};
	cout << count << endl;
	return 0;
}
