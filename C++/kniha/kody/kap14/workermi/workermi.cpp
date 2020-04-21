// workermi.cpp -- metody tøíd pracovníkù s VD
#include "workermi.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
// Worker methods
Worker::~Worker() { }

// protected methods
void Worker::Data() const
{
	cout << "Jmeno: " << fullname << endl;
	cout << "ID zamestnance: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "Zadejte ID pracovnika: ";
	cin >> id;
	while (cin.get() != '\n')
	continue;
}

// Waiter methods
void Waiter::Set()
{
	cout << "Zadejte jmeno cisnika: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Kategorie: cisnik\n";
	Worker::Data();
	Data();
}

// protected methods
void Waiter::Data() const
{
	cout << "Hodnoceni hbitosti: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Zadejte hbitost cisnika: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

// Singer methods

char * Singer::pv[Singer::Vtypes] = {"östatni", "alt", "kontraalt",
				"sopran", "bas", "baryton", "tenor"};

void Singer::Set()
{
	cout << "Zadejte jmeno pevce: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "Kategorie: pevec\n";
	Worker::Data();
	Data();
}

// protected methods
void Singer::Data() const
{
	cout << "Hlasovy rozsah: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "Zadejte cislo pevcova hlasoveho rozsahu:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if ( i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
			cout << '\n';
		cin >> voice;
		while (cin.get() != '\n')
			continue;
}

// SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout << "Zadejte jmeno zpivajiciho cisnika: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "kategorie: zpivajici cisnik\n";
	Worker::Data();
	Data();
}
