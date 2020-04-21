#include <iostream>
#include <string>

using namespace std;
int main()
{
	char char1[20];
	char char2[20] = "jaguar";
	string str1;
	string str2 = "panter";
	
	cout << "Zadajte mackovytu selmu: " << endl;
	cin >> char1;
	cout << "Zadajte inu mackovitu selmu: " << endl;
	cin >> str1;
	
	cout << char1 << " " << char2 << " " << str1 << " " << str2 << endl;
}
