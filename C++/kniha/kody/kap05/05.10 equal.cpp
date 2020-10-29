// equal.cpp -- rovnost proti pøiøazení
#include <iostream>
int main()
{
	using namespace std;
	int quizscores[10] =
		{20, 20, 20, 20, 20, 19, 20, 18, 20, 20};

	cout << "Provedeno spravne:\n";
	int i;
	for (i = 0; quizscores[i] == 20; i++)
		cout << "kviz " << i << " je 20\n";

	cout << "Provedeno nebezpecne spatne:\n";
	for (i = 0; quizscores[i] = 20; i++)
		cout << "kviz " << i << " je 20\n";

	return 0;
}
