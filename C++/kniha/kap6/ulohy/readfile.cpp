#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	char filename[80];
	cout << "Enter a name of file to read: " << endl;
	cin.getline(filename, 80);
	
	ifstream readFile;
	readFile.open(filename);
	if (!readFile.is_open())
	{
		cout << "Couldnt open a file!" << endl;
		exit(EXIT_FAILURE);
	}
	
	int count = 0;
	char ch;
	readFile >> ch;
	cout << ch;
	while (readFile.good())
	{
		count++;
		cout << ch;
		readFile >> ch;
	}
	
	readFile.close();
	cout << count << " characters in " << filename << endl;
	return 0;
}
