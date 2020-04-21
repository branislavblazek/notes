#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	char char1[20];
	char char2[20] = "jaguarovy";
	
	string str1;
	string str2 = "panterove";
	
	str1 = str2;//copy str2 to str1
	strcpy(char1, char2);//copy char2 to chat1
	
	str1 += " cesto";//conenct " cesto" at the end of str1
	strcat(char1, " dzus");//connect " dzus" at the end of char1
	
	int len1 = str1.size();
	int len2 = strlen(char1);
	
	cout << "Retazec " << str1 << " obsahuje " << len1 << " znakov" << endl;
	cout << "Retazec " << str2 << " obsahuje " << len2 << " znakov" << endl;
	
	return 0;
}
