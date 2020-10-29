// tempover.cpp -- pøetìžování šablon
#include <iostream>

template <typename T> // šablona A
void ShowArray(T arr[], int n);

template <typename T> // šablona B
void ShowArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main(void)
{
	using namespace std;
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe ", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];

// Nastavení ukazatelù na skupinu èlenù struktury v poli mr_E
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "Vypis souctu veci pana E:\n";
// Vìci jsou v poli int
	ShowArray(things, 6); // použije šablonu A
	cout << "Vypis dluhu pana E:\n";
// pd je pole ukazatelù na double
	ShowArray(pd, 3); // použije šablonu B (specializovanìjší)
	
	return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "sablona A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
	using namespace std;
	cout << "sablona B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}
