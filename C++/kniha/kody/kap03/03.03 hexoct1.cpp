// hexoct1.cpp - pøíklady hexadecimálních a oktalovıch konstant
#include <iostream>
int main()
{
using namespace std;
int chest = 76; 				// dekadická celoèíselná konstanta
int waist = 0x76; 			// hexadecimální celoèíselná konstanta
int inseam = 076; 			// oktalová celoèíselná konstanta
cout << "Pan ma pozoruhodnou postavu!\n";
cout << "hrudnik = " << chest << "\n";
cout << "pas = " << waist << "\n";
cout << "sed = " << inseam << "\n";

return 0;
}
