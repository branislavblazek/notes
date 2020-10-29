// strgstl.cpp -- aplikace STL na øetìzec
#include <iostream>
#include <string>
#include <algorithm>
int main()
{
using namespace std;
string letters;
cout << "Zadejte skupinu pismen (nebo konec): ";
while (cin >> letters && letters != "konec")
{
cout << "Permutace " << letters << endl;
sort(letters.begin(), letters.end());
cout << letters << endl;
while (next_permutation(letters.begin(), letters.end()))
cout << letters << endl;
cout << "Zadejte dalsi posloupnost (nebo konec): ";
}
cout << "Hotovo.\n";
return 0;
}
