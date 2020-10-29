// studenti.cpp -- tøída Student pouívá soukromou dìdiènost
#include "studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// veøejné metody
double Student::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum()/ArrayDb::size();
	else
		return 0;
}

const string & Student::Name() const
{
	return (const string &) *this;
}

double & Student::operator[](int i)
{
	return ArrayDb::operator[](i); // pouití ArrayDb::operator[]()
}

double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

// private method
ostream & Student::arr_out(ostream & os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << " prazdne pole ";
	return os;
}

// pøátelé
// pouití verze string funkce operator>>()
istream & operator>>(istream & is, Student & stu)
{
	is >> (string &)stu;
	return is;
}

// pouití pøítele typu string getline(ostream &, const string &)
istream & getline(istream & is, Student & stu)
{
	getline(is, (string &)stu);
	return is;
}

// pouití verze string funkce operator<<()
ostream & operator<<(ostream & os, const Student & stu)
{
	os << "Vysledky " << (const string &) stu << ":\n";
	stu.arr_out(os); // pouití soukromé metody pro hodnocení
	return os;
}
