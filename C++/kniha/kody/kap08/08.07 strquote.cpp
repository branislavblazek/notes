// strquote.cpp - rùzné konstrukce
#include <iostream>
#include <string>
using namespace std;
string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2); // má vedlejší úèinek
const string & version3(string & s1, const string & s2); // špatná konstrukce

int main()
{
	string input;
	string copy;
	string result;

	cout << "Zadejte retezec: ";
	getline(cin, input);
	copy = input;
	cout << "Zadany retezec: " << input << endl;
	result = version1(input, "***");
	cout << "Pridavany retezec: " << result << endl;
	cout << "Puvodni retezec: " << input << endl;

	result = version2(input, "###");
	cout << "Pridavany retezec: " << result << endl;
	cout << "Puvodni retezec: " << input << endl;

	cout << "Obnova puvodniho retezce.\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "Pridavany retezec: " << result << endl;
	cout << "Puvodni retezec: " << input << endl;
	return 0;
}

string version1(const string & s1, const string & s2)
{
	string temp;

	temp = s2 + s1 + s2;;
	return temp;
}

	const string & version2(string & s1, const string & s2) // má vedlejší úèinek
{
	s1 = s2 + s1 + s2;
// bezpeèné vrácení odkazu pøedaného funkci 
	return s1;
}

const string & version3(string & s1, const string & s2) // špatná konstrukce
{
	string temp;

	temp = s2 + s1 + s2;
// vrácení odkazu v lokální promìnné není bezpeèné
	return temp;
}
