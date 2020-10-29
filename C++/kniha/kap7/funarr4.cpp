#include <iostream>
using namespace std;
const int ArSize = 8;
int sum_array(const int * begin, const int * end);
int main()
{
	int cookies[ArSize] = {1, 2,4,8,16,32,64,128};
	int sum = sum_array(cookies, cookies + ArSize);
	cout << "Spolu " << sum << endl;
	sum = sum_array(cookies, cookies+3);
	cout << "Prve tri: " << sum <<endl;
	sum = sum_array(cookies + 4, cookies + ArSize);
	cout << "Posledne 4: " << sum << endl;
	return 0;
}

int sum_array(const int * begin, const int * end)
{
	const int * pt;
	int total = 0;
	
	for (pt = begin; pt != end; pt++)
	{
		total += *pt;
	}
	return total;
}

