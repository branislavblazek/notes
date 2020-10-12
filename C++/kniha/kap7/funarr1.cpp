#include <iostream>
using namespace std;

int sum_array(int arr[], int n);

int main()
{
	int cookies[8] = {2,4,6,8,16,32,64,128};
	int sum = sum_array(cookies, 8);
	cout << "Celkovy pocet je " << sum << endl;
}

int sum_array(int arr[], int n)
{
	int total;
	for (int i = 0; i < n; i++)
	{
		total += arr[i];
	}
	return total;
}
