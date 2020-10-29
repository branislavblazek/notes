#include <iostream>
using namespace std;

int main()
{
	const int ar_size = 16;
	double faktorialy[ar_size];
	faktorialy[0]  = 1.0;
	for (int i = 1; i < ar_size; i++)
	{
		faktorialy[i] = i * faktorialy[i-1];
	}
	
	for (int i = 0; i < ar_size; i++)
	{
		cout << i << "! = " << faktorialy[i] << endl;
	}
}
