// inserts.cpp -- funkce copy() a iterátory vkládání
#include <iostream>
#include <string>
#include <iterator>
#include <vector>

int main()
{ 
	using namespace std;
	string s1[4] = {"pekna", "ryba", "osud", "mody"};
	string s2[2] = {"pilni", "netopyri"};
	string s3[2] = {"hloupi", "zpevaci"};
	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	ostream_iterator<string, char> out(cout, " ");
	copy (words.begin(), words.end(), out);
	cout << endl;

// vytvoøí anonymní objekt back_insert_iterator
	copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words));
	copy (words.begin(), words.end(), out);
	cout << endl;

// vytvoøí anonymní objekt insert_iterator
	copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin()));
	copy (words.begin(), words.end(), out);
	cout << endl;

	return 0;
}
