#include <iostream>
using namespace std;

int main()
{
	cout << "Zadajte svoj tajny kod:_________\b\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\t\tVas kod je " << code << "...\n";
	cout << '\a';
	return 0;
}
