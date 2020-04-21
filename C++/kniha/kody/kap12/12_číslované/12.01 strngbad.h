// strngbad.h -- definice špatné tøídy string
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class StringBad
{
private:
	char * str; // ukazatel na øetìzec
	int len; // délka øetìzce
	static int num_strings; // poèet objektù
public:
	StringBad(const char * s); // konstruktor
	StringBad(); // implicitní konstruktor
	~StringBad(); // destruktor
// pøátelská funkce
	friend std::ostream & operator<<(std::ostream & os,
										const StringBad & st);
};
#endif
