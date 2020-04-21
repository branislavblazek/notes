// bigstep.cpp -- pøièítání podle zadání
#include <iostream>
int main()
{
	using namespace std;
	cout << "Zadejte cele cislo: ";
	int by;
	cin >> by;
	cout << "Pricitani po " << by << ":\n";
	for (int i = 0; i < 100; i = i + by)
		cout << i << endl;
	
	return 0;
}
