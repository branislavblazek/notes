// acctabc.cpp -- metody tøídy bankovních úètù
#include <iostream>
#include <cstring>
using std::cout;
using std::ios_base;
using std::endl;

#include "acctabc.h"

// Abstract Base Class
AcctABC::AcctABC(const char *s, long an, double bal)
{
	std::strncpy(fullName, s, MAX - 1);
	fullName[MAX - 1] = '\0';
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		cout << "Zaporna ulozka je nepripustna; "
				<< "ulozka zrusena.\n";
	else
		balance += amt;
}

void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}

// chránìná metoda
ios_base::fmtflags AcctABC::SetFormat() const
{
	// set up ###.## format
	ios_base::fmtflags initialState =
			cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	return initialState;
}

// metody Brass
void Brass::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Vybirana castka musi byt kladna; "
				<< "vyber zrusen.\n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Vybirana castka $" << amt
				<< " je vyssi nez zustatek.\n"
				<< "Vyber zrusen.\n";
}

void Brass::ViewAcct() const
{
	ios_base::fmtflags initialState = SetFormat();
	cout << "Klient Brass: " << fullName << endl;
	cout << "Cislo uctu: " << acctNum << endl;
	cout << "Zustatek: $" << balance << endl;
	cout.setf(initialState);
}

// Metody BrassPlus
BrassPlus::BrassPlus(const char *s, long an, double bal,
				double ml, double r) : AcctABC(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
			: AcctABC(ba) // použití implicitního kopírovacího konstruktoru
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	ios_base::fmtflags initialState = SetFormat();
	cout << "Klient BrassPlus: " << FullName() << endl;
	cout << "Cislo uctu: " << AcctNum() << endl;
	cout << "Zustatek: $" << Balance() << endl;
	cout << "Maximalni pujcka: $" << maxLoan << endl;
	cout << "Dluh bance: $" << owesBank << endl;
	cout << "Sazba za dluh: " << 100 * rate << "%\n";
	cout.setf(initialState);
}

void BrassPlus::Withdraw(double amt)
{
	ios_base::fmtflags initialState = SetFormat();

	double bal = Balance();
	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if ( amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Pujcky od banky: $" << advance << endl;
		cout << "Poplatek: $" << advance * rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Prekrocen limit uveru. Transakce zrusena.\n";
	cout.setf(initialState);
}
