// vect1.cpp -- úvod do šablony vector
#include <iostream>
#include <string>
#include <vector>


const int NUM = 5;
int main()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;

	vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout << "Postupujte presne podle navodu. Zadate\n"
			<< NUM << " nazvu knih a ohodnotite je znamkou 0-10.\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << "Zadejte nazev c. " << i + 1 << ": ";
		getline(cin, titles[i]);
		cout << "Zadejte hodnoceni znamkou 0-10: ";
		cin >> ratings[i];
		cin.get();
	}
	cout << "Dekuji. Zadali jste nasledujici nazvy:\n"
			<< "Znamka\tKniha\n";
	for (i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}

	return 0;
}
