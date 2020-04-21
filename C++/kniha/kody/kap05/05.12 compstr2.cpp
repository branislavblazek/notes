// compstr2.cpp -- comparing strings using arrays
#include <iostream>
#include <string> 	// tøída string
int main()
{
	using namespace std;
	string word = "?ate";

	for (char ch = 'a'; word != "mate"; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	cout << "Po skonceni cyklu je slovo " << word << endl;
	
	return 0;
}
