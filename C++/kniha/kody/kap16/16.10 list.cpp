// list.cpp -- použití kontejneru list
#include <iostream>
#include <list>
#include <iterator>
int main()
{
	using namespace std;
	list<int> one(5, 2); // seznam 5 kvót hodnota 2
	int stuff[5] = {1, 2, 4, 8, 6};
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = {6, 4, 2, 4, 6, 5};
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "Seznam one: ";
	ostream_iterator<int,char> out(cout, " ");
	copy(one.begin(), one.end(), out);
	cout << endl << "Seznam two: ";
	copy(two.begin(), two.end(), out);
	cout << endl << "Seznam three: ";
	copy(three.begin(), three.end(), out);
	three.remove(2);
	cout << endl << "Seznam three bez dvojek: ";
	copy(three.begin(), three.end(), out);
	three.splice(three.begin(), one);
	cout << endl << "Seznam three po provedeni funkce splice(): ";
	copy(three.begin(), three.end(), out);
	cout << endl << "Seznam one: ";
	copy(one.begin(), one.end(), out);
	three.unique();
	cout << endl << "Seznam three po provedeni funkce unique(): ";
	copy(three.begin(), three.end(), out);
	three.sort();
	three.unique();
	cout << endl << "Seznam three po setrideni a po provedeni funkce unique(): ";
	copy(three.begin(), three.end(), out);
	two.sort();
	three.merge(two);
	cout << endl << "Setrideny seznam two slouceny se seznamem three: ";
	copy(three.begin(), three.end(), out);
	cout << endl;

	return 0;
}
