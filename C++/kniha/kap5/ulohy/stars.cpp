#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int dots, stars;
	
	for (int i = 0; i < n; i++)
	{
		dots = n - i - 1;
		stars = i + 1;
		
		for (int y = 0; y < dots; y++)
		{
			cout << ".";	
		}
		
		for (int z = 0; z < stars; z++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
