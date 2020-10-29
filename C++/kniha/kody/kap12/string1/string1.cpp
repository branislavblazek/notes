// string1.cpp -- metody tøídy String
#include <cstring> // nìkdy string.h 
#include "string1.h" // obsahuje <iostream>
using std::cin;
using std::cout;

// inicializace èlena statické tøídy

int String::num_strings = 0;

// statické metody
int String::HowMany()
{
	return num_strings;
}

// metody tøídy
String::String(const char * s) // konstrukce String z øetìzce C
{
	len = std::strlen(s); // nastav velikost
	str = new char[len + 1]; // pøidìl pamì
	std::strcpy(str, s); // inicializuj ukazatel
	num_strings++; // nastav èítaè objektù
}

String::String() // implicitní konstruktor
{
	len = 4;
	str = new char[1];
	str[0] = '\0'; // implicitní øetìzec
	num_strings++;
}

String::String(const String & st)
{
	num_strings++; // aktualizace statického èlena
	len = st.len; // stejná délka
	str = new char [len + 1]; // pøidìl pamì
	std::strcpy(str, st.str); // zkopíruj øetìzec na nové místo
}

String::~String() // nezbytnı destruktor
{
	--num_strings; // nutné
	delete [] str; // nutné
}

// metody pøetíeného operátoru

		// String pøiøaï String
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

		// C string pøiøaï String
String & String::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

		// znakovı pøístup ètení/zápis pro nekonstantní String
char & String::operator[](int i)
{
	return str[i];
}

		// znakovı pøístup pouze pro ètení pro konstantní String 
const char & String::operator[](int i) const
{
	return str[i];
}

// pøátelé pøetíeného operátoru

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return st2.str < st1.str;
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

		// jednoduchı vıstup String 
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

		// rychlı a neèistı vstup String
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
