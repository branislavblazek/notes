// ifelse.cpp -- pouití pøíkazu if else
#include <iostream>
int main()
{
	using namespace std;
	char ch;

	cout << "Piste a ja budu opakovat.\n";
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
			cout << ch; 		// provádí se, kdy ch je znak nového øádku
		else
			cout << ch+1; 		// provádí se jindy
		cin.get(ch);
	}
// zkuste ch + 1 místo ++ch kvùli zajímavému dùsledku
	cout << "\nProsim, omluvte male nedorozumeni.\n";
	
	return 0;
}
