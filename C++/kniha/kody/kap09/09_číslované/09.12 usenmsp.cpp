// usenmsp.cpp -- používání jmenných prostorù
#include <iostream>
#include "namesp.h"

void jiny(void);
void dalsi(void);
int main(void)
{
    using dluhy::Dluh;
    using dluhy::ukazDluh;
    Dluh golf = { {"Benny", "Goatsnift"}, 120.0};
    ukazDluh(golf);
    jiny();
    dalsi();

    return 0;
}

void jiny(void)
{
    using std::cout;
    using std::endl;
    using namespace dluhy;
    Osoba dg = {"Doodles", "Glister"};
    ukazOsobu(dg);
    cout << endl;
    Dluh zippy[3];
    int i;

    for (i = 0; i < 3; i++)
        vlozDluh(zippy[i]);
    for (i = 0; i < 3; i++)
        ukazDluh(zippy[i]);
    cout << "Celkovy dluh: " << sectiDluhy(zippy, 3) << " Kc" << endl;

    return;
}

void dalsi(void)
{
    using osoby::Osoba;

    Osoba vyberci = {"Milo", "Rightshift"};
    osoby::ukazOsobu(vyberci);
    std::cout << endl;
}
