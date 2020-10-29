// str1.cpp -- úvod do tøídy string
#include <iostream>
#include <string>
// použití konstruktorù tøídy string

int main()
{
	using namespace std;
	string one("Bolek zvitezil v loterii!"); 	// 1.konstruktor (ctor è.1)
	cout << one << endl; 										// pøetížený operátor <<
	string two(20,'$'); 										// 2.konstruktor (ctor è.2)
	cout << two << endl;
	string three(one); 										// 3.konstruktor (ctor è.3)
	cout << three << endl;
	one += " Moment!" ; 										// pøetížený operátor +=
	cout << one << endl;
	two = "Prominte! Melo to byt ";
	three[0] = 'L';
	string four; 													// 4.konstruktor (ctor è.4)
	four = two + three; 										// pøetížený operátor =
	cout << four << endl;
	char alls[] = "Konec dobry, vsechno dobre";
	string five(alls,20); 									// 5.konstruktor (ctor è.5)
	cout << five <<"!\n";
	string six(alls+6, alls + 11); 					// 6.konstruktor (ctor è.6)
	cout << six << ", ";
	string seven(&five[6], &five[11]); 				// opìt 6.konstruktor
	cout << seven << "...\n";
	
	return 0;
}
