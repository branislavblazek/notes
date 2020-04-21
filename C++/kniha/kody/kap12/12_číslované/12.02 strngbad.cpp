// strngbad.cpp -- metody tøídy StringBad
#include <cstring> 		// nìkdy také string.h
#include "strngbad.h"
using std::cout;

// inicializace statické poloky tøídy
int StringBad::num_strings = 0;

// metody tøídy

// konstrukce StringBad z øetzce typu C 
StringBad::StringBad(const char * s)
{
	len = std::strlen(s); 					// nastaví velikost
	str = new char[len + 1]; 				// pøidìlí pamì
	std::strcpy(str, s); 						// inicializuje ukazatel
	num_strings++; 								// nastaví èítaè objektù
	cout << num_strings << ": \"" << str
			<< "\" object created\n"; 	// Informace pro obsluhu
}

StringBad::StringBad() // implicitní konstruktor
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++"); 									// implicitní øetìzec
	num_strings++;
	cout << num_strings << ": \"" << str
			<< "\" implicitni objekt vytvoren\n"; 	// FYI
}

StringBad::~StringBad() 										// nutnı destruktor
{
	cout << "\"" << str << "\"objekt zrusen, "; 	// FYI
	--num_strings; 													// nutné
	cout << num_strings << " left\n"; 					// FYI
	delete [] str; 													// nutné
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
	os << st.str;
	return os;
}
