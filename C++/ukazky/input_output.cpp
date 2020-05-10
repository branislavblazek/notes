#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	char in_file_name[80];
	char out_file_name[80];
	
	cout << "Zadajte nazov vstupneho suboru: " << endl;
	cin.getline(in_file_name, 80);
	cout << "Zadajte nazov vystupneho suboru: " << endl;
	cin.getline(out_file_name, 80);
	
	ifstream in_file;
	ofstream out_file;
	
	in_file.open(in_file_name);
	out_file.open(out_file_name);
	
	if (!in_file.is_open())
	{
		cout << "Nepodarilo sa mi otvorit vstupny subor." << endl;
		exit(EXIT_FAILURE);
	}
	
	char line[100];
	int index_line = 1;
	out_file << "Source: " << in_file_name << endl;
	
	while (in_file.getline(line, 100))
	{
		out_file << "#" << index_line << ". "<< line << endl;
		index_line++;
	}
	
	if (in_file.eof())
	{
		out_file << "Koniec suboru." << endl;
	}
	else if (in_file.fail())
	{
		out_file << "Citanie sa ukoncilo, nespravne data." << endl;
	}
	else 
	{
		out_file << "Citanie sa ukoncilo z nezistenenho dovodu." << endl;
	}
	
	in_file.close();
	return 0;
}
