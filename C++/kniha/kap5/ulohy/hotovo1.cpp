#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int count = 0;
	cout << "zadajte slova, ukoncite slovom hotovo" << endl;
	char word[20];
	while(cin >> word && strcmp(word, "hotovo"))
		count++;
		
	cout << "Zadali ste " << count << " slov" << endl;
	return 0;
}
