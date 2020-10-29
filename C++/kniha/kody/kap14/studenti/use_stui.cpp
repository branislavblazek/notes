// use_stui.cpp -- pouití tøídy se soukromou dìdièností
// pøeloit se studenti.cpp
#include <iostream>
#include "studenti.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student ada[pupils] =
		{Student(quizzes), Student(quizzes), Student(quizzes)};
	int i;
	for (i = 0; i < pupils; i++)
		set(ada[i], quizzes);
	cout << "\nSeznam studentu:\n";
	for (i = 0; i < pupils; ++i)
		cout << ada[i].Name() << endl;
	cout << "\nVysledky:";
	for (i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "prumer: " << ada[i].Average() << endl;
	}
	cout << "Hotovo.\n";
	system("PAUSE");
	return 0;
}

void set(Student & sa, int n)
{
	cout << "Zadejte prosim jmeno studenta: ";
	getline(cin, sa);
	cout << "Zadejte prosim hodnoceni z " << n << " zkousek:\n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}
