#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	cout << "Zadajte text na analyzu, @ ukonci. " << endl;
	
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int other = 0;
	
	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			other++;
		cin.get(ch);
	}
	cout << chars <<  " pismen, " << 
		digits << " cislic, " << 
		whitespace << " medzier, " <<
		punct << " interpunkcie, " <<
		other << " ostatneho" << endl;
		
	return 0;
}
