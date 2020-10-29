// rtti2.cpp - použití operátorù dynamic_cast, typeid a type_info
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { cout << "Jsem velkolepa trida!\n";}
	virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	void Speak() const {cout << "Jsem super trida!!\n"; }
	virtual void Say() const
		{ cout << "Obsahuji super hodnotu " << Value() << "!\n";}
};

class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	void Speak() const {cout << "Jsem skvela trida!!!\n";}
	void Say() const {cout << "Obsahuji znak " << ch <<
	" a cele cislo " << Value() << "!\n"; }
};

Grand * GetOne();
int main()
{
	std::srand(std::time(0));
	Grand * pg;
	Superb * ps;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		cout << "Nyni zpracovavam typ " << typeid(*pg).name() << ".\n";
		pg->Speak();
		if( ps = dynamic_cast<Superb *>(pg))
			ps->Say();
		if (typeid(Magnificent) == typeid(*pg))
			cout << "Ano, opravdu jsi skvela.\n";
	}
	return 0;
}

Grand * GetOne() // vytvoøí náhodnì jeden ze tøí druhù objektù
{
	Grand * p;
	switch( std::rand() % 3)
	{
	case 0: p = new Grand(std::rand() % 100);
								break;
	case 1: p = new Superb(std::rand() % 100);
								break;
	case 2: p = new Magnificent(std::rand() % 100,
										'A' + std::rand() % 26);
								break;
	}
	return p;
}
