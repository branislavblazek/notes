#include <iostream>
using namespace std;

int main()
{
	const int Max = 5;
	double fish[Max];
	cout << "Zadajte vahy ryb" << endl;
	cout << "ryba c. 1" << endl;
	int i = 0;
	while (i < Max && cin >> fish[i])
	{
		if (++i < Max)
		{
			cout << "ryba c. " << i+1 << endl;
		}
	}
	
	double total = 0.0;
	for (int j = 0; j < i; j++)
	{
		total += fish[j];
	}
	if (i == 0)
	{
		cout << "Nie je to ziadna ryba!" << endl;
	}
	else 
	{
		cout << total / i << " = priemerna vaha " << i << " ryb" << endl;
	}
	return 0;
}
