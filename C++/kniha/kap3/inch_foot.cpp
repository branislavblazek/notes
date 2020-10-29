#include <iostream>
using namespace std;

const int Inch_Per_Foot = 12;

int main()
{
	cout << "Prosim zadajte svoju vysku v palcoch: ___\b\b\b ";
    int ht_inch;
    cin >> ht_inch;
    int ht_feet = ht_inch / Inch_Per_Foot;
    int rm_inch = ht_inch % Inch_Per_Foot;
    cout << "Vasa vyska je " << ht_feet << " stop, ";
    cout << rm_inch << " palcov.\n";
    return 0;
}
