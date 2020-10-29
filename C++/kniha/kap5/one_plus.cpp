#include <iostream>
using namespace std;

int main()
{
	int a = 20;
	int b = 20;
	
	cout << "a = " << a << ": b = " << b << endl;
	cout << "a++ = " << a++ << ": ++b = " << ++b << endl;
	cout << "a = " << a << ": b = " << b << endl;
	
	int g = 0;
	while (g++ < 10)
	{
		cout << g << endl;
	}
	
	return 0;
}
