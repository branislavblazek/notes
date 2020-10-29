// strtype3.cpp -- dalsi vlastnosti tridy string
#include <iostream>
#include <string> 				// zpøístupnìní tøídy string
#include <cstring> 			// knihovna C pro zpracování øetìzcù
int main()
{

	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguarovy";
	string str1;
	string str2 = "panterove";

	// prirazovani retezcovym objektum a znakovym polim
	str1 = str2; 							// zkopíruj str2 do str1
	strcpy(charr1, charr2); 		// zkopíruj charr2 do charr1

	// pripojovani k retezcovym objektum a ke znakovym polim
	str1 += " testo"; 					// ke konci str1 pripoj testo
	strcat(charr1, " dzus"); 		// ke konci charr1 pripoj dzus 

	// zjistovani delky retezcoveho objektu a klasickeho retezce
	int len1 = str1.size(); 		// delka str1
	int len2 = strlen(charr1); 	// delka charr1

	cout << "Retezec " << str1 << " obsahuje "
			<< len1 << " znaku.\n";
	cout << "Retezec " << charr1 << " obsahuje "
			<< len2 << " znaku.\n";

	return 0;
}
