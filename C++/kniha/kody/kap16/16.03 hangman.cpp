// hangman.cpp -- nìkteré metody tøídy string
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using std::string;
const int NUM = 26;
const string wordlist[NUM] = {"vcelin", "kobyla", "jecmen",
	"noviny", "vlajka", "ibisek", "fialka", "zdravi", "urazka",
	"medved", "stovik", "hribek", "moudry", "laciny", "stolek",
	"prehoz", "perina", "daleko", "siroko", "koleje", "cirkus",
	"platny", "candat", "kamzik", "touzit", "zirafa"};

int main()
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;

	std::srand(std::time(0));
	char play;
	cout << "Chcete si zahrat hru se slovy? <a/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'a')
	{
		string target = wordlist[std::rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Dam vam hadat slovo. Ma " << length
				<< " pismen a budete hadat\n"
				<< "vzdy jedno pismeno. Jestlize " << guesses
				<< "x neuhodnete, prohravate.\n";
		cout << "Zde je slovo: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Hadejte pismeno: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "To jste jiz hadal. Zkuste znovu.\n";
					continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Chyba!\n";
				--guesses;
				badchars += letter; // pøidá písmeno do øetìzce
			}
			else
			{
				cout << "Spravne!\n";
				attempt[loc] = letter;
				// kontroluje další výskyt písmene
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc]=letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Slovo je: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Chybne pokusy: " << badchars << endl;
				cout << "Zbyva " << guesses << " pokusu.\n";
			}
		}
		if (guesses > 0)
			cout << "Gratuluji!\n";
		else
			cout << "Bohuzel, slovo je " << target << ".\n";

		cout << "Chcete pokracovat? <a/n> ";
		cin >> play;
		play = tolower(play);
	}
	cout << "Nazdar!\n";

	return 0;
}
