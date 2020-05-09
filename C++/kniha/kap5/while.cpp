#include <iostream>
using namespace std;

const int ar_size = 20;

int main()
{
	char name[ar_size];
	cout << "Vase krstne meno: ";
	cin >> name;
	cout << "Tu je vase meno suvisle s ASCII kody: " << endl;
	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i] << ": " << int(name[i]) << endl;
		i++;
	}
	return 0;
}
