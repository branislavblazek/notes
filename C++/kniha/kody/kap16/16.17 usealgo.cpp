//usealgo.cpp -- použití nìkolika prvkù STL
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

char toLower(char ch) { return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);

int main()
{
	vector<string> words;
	cout << "Zadejte slova (\"konec\" pro ukonceni):\n";
	string input;
	while (cin >> input && input != "konec")
		words.push_back(input);

	cout << "Zadali jste nasledujici slova:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	// vložení slov do kontejneru typu set, konverze na malá písmena
	set<string> wordset;
	transform(words.begin(), words.end(),
		insert_iterator<set<string> > (wordset, wordset.begin()),
		ToLower);
	cout << "\nSeznam slov podle abecedy:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	// vložení slov a poèet výskytù do kontejneru typu map
	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si);

	// zobrazení obsahu kontejneru typu map
	cout << "\nPocet vyskytu:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ": " << wordmap[*si] << endl;

	return 0;
}

string & ToLower(string & st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void display(const string & s)
{
	cout << s << " ";
}
