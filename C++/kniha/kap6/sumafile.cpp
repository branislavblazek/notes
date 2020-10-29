#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int size = 60;
int main()
{
	char filename[size];
	ifstream inFile;
	
	cout << "Zadajte meno datoveho suboru: ";
	cin.getline(filename, size);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Nepodarilo sa otvorit subor " << filename << endl;
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;
	
	inFile >> value;
	while (inFile.good()) //while not EOF or something else
	{
		++count;
		sum += value;
		inFile >> value;
	}
	if (inFile.eof())
	{
		cout << "Koniec suboru" << endl;
	}
	else if (inFile.fail())
	{
		cout << "Citanie sa ukoncilo, nespravne data" << endl;
	}
	else 
	{
		cout << "Citanie sa ukoncilo" << endl;
	}
	
	if (count == 0)
	{
		cout << "Nespracovali sa ziadne data" << endl;
	}
	else
	{
		cout << "Pocet precitanych poloziek: " << count << endl;
		cout << "Sucet: " << sum << endl;
		cout << "Priemer: " << sum / count << endl;
	}
	
	inFile.close();
	return 0;
}
