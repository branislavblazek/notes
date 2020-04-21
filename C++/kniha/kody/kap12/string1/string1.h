// string1.h - opravená a rozšíøená definice tøídy string
#include <iostream>
using std::ostream;
using std::istream;

#ifndef STRING1_H_
#define STRING1_H_
class String
{
private:
	char * str; 						// ukazatel na øetìzec
	int len; 								// délka øetìzce
	static int num_strings; 	// poèet objektù
	static const int CINLIM = 80; // vstupní limit cin 
public:
// konstruktory a další metody
	String(const char * s); // 
	String(); // implicitní konstruktor
	String(const String &); // kopíruj konstruktor
	~String(); // destruktor
	int length () const { return len; }
// metody pøetíženého operátoru
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
// pøátelé pøetíženého operátoru
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream & os, const String & st);
	friend istream & operator>>(istream & is, String & st);
// statická funkce
	static int HowMany();
};
#endif
