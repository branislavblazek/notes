// strtype2.cpp -- prirazovani, pridavani a pripojovani
#include <iostream>
#include <string> 		// zpøístupnìní tøídy string
int main()
{
	using namespace std;
	string s1 = "tucnak";
	string s2, s3;

	cout << "Retezcove objekty muzete prirazovat: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "Retezce v C muzete prirazovat retezcovym objektum.\n";
	cout << "s2 = \"tucnak\"\n";
	s2 = "tucnak";
	cout << "s2: " << s2 << endl;
	cout << "Promenne typu string muzete zretezovat: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "Retezce muzete pripojovat.\n";
	s1 += s2;
	cout <<"Vysledkem s1 += s2 je s1 = " << s1 << endl;
	s2 += " na den";
	cout <<"Vysledkem s2 += \" na den\" je s2 = " << s2 << endl;

	return 0;
}
