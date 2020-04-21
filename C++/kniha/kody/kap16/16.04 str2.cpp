// str2.cpp -- metody capacity() a reserve()
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	string empty;
	string small = "bit";
	string larger = "Nejlepsim pritelem divek jsou sloni";
	cout << "Velikosti:\n";
	cout << "\tprazdny: " << empty.size() << endl;
	cout << "\tmaly: " << small.size() << endl;
	cout << "\tvetsi: " << larger.size() << endl;
	cout << "Kapacity:\n";
	cout << "\tprazdny: " << empty.capacity() << endl;
	cout << "\tmaly: " << small.capacity() << endl;
	cout << "\tvetsi: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "Kapacita po empty.reserve(50): "
			<< empty.capacity() << endl;
	return 0;
}
