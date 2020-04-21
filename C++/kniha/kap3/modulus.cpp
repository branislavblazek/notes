#include <iostream>
using namespace std;

int main()
{
	const int lbs_to_stn = 14;
	int lbs;
	cout << "Zadajte svoju vahu v librach: ";
	cin >> lbs;
	int stone = lbs / lbs_to_stn;
	int pounds = lbs % lbs_to_stn;
	
	cout << lbs << " libier je " << stone << " kamenov a " << pounds << " libier" << endl;
	return 0;
	
}
