#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Zadajte slovo: " << endl;
	string slovo;
	cin >> slovo;
	
	for (int i = slovo.size() - 1; i >=0; i--)
	{
		cout << slovo[i];
	}
	cout << endl;
	
	return 0;
}
