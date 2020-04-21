// brass.cpp -- metody tøídy bank account
#include <iostream>
#include <cstring>
#include "brass.h"
using std::cout;
using std::ios_base;
using std::endl;
// metody Brass 

Brass::Brass(const char *s, long an, double bal)
{
	std::strncpy(fullName, s, MAX - 1);
	fullName[MAX - 1] = '\0';
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Zaporna ulozka je nepripustna; "
				<< "ulozka zrusena.\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Vybirana castka musi byt kladna; "

				<< "vyber zrusen.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Vybirana castka $" << amt
				<< " je vyssi nez zustatek.\n"
				<< "Vyber zrusen.\n";
}
double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	// nastav format ###.##
	ios_base::fmtflags initialState =
			cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	cout << "Klient: " << fullName << endl;
	cout << "Cislo uctu: " << acctNum << endl;
	cout << "Zustatek: $" << balance << endl;
	cout.setf(initialState); // obnov pùvodní formát
}

// Metody BrassPlus Methods
BrassPlus::BrassPlus(const char *s, long an, double bal,
				double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
				: Brass(ba) // použij implicitní kopírovací konstruktor
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

// pøedefinuj èinnist ViewAcct() 
void BrassPlus::ViewAcct() const
{
	// nastav formát ###.## 
	ios_base::fmtflags initialState =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);

	Brass::ViewAcct(); // výpis základní èásti
	cout << "Maximalni vyse pujcky: $" << maxLoan << endl;
	cout << "Pujcka od banky: $" << owesBank << endl;
	cout << "Sazba za uver: " << 100 * rate << "%\n";
	cout.setf(initialState);
}

// pøedefinuj èinnist Withdraw()
void BrassPlus::Withdraw(double amt)
{
// nastav formát ###.##
	ios_base::fmtflags initialState =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if ( amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Pujcka od banky: $" << advance << endl;
		cout << "Poplatek: $" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Prekrocen kreditni limit. Transakce zrusena.\n";
	cout.setf(initialState);
} 
