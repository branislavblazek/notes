//error3.cpp -- vyuití vıjimky
#include <iostream>
double hmean(double a, double b);
int main()
{
double x, y, z;
std::cout << " Zadejte dve cisla: ";
while (std::cin >> x >> y)
{
try { // zaèátek pokusného bloku
z = hmean(x,y);
} // konec pokusného bloku
catch (const char * s) // zaèátek handleru vıjimky
{
std::cout << s << std::endl;
std::cout << "Zadejte novou dvojici cisel: ";
continue;
} // konec handleru
std::cout << "Harmonicky prumer cisel " << x << " a " << y
<< " je " << z << std::endl;
std::cout << "Zadejte dalsi mnozinu cisel <k pro ukonceni>: ";
}
std::cout << "Nashledanou!\n";
return 0;
}
double hmean(double a, double b)
{
if (a == -b)
throw "Neplatne parametry ve funkci hmean(): a = -b neni povoleno";
return 2.0 * a * b / (a + b);
}
