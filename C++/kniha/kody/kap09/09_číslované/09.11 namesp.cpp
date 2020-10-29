// namesp.cpp -- jmenné prostory
#include <iostream>
#include "namesp.h"

namespace osoby
{
    using std::cout;
    using std::cin;
    void vlozOsobu(Osoba & ro)
    {
        cout << "Zadejte krestni jmeno: ";
        cin >> ro.jmeno;
        cout << "Zadejte prijmeni: ";
        cin >> ro.prijmeni;
    }

    void ukazOsobu(const Osoba & ro)
    {
        cout << ro.prijmeni << ", " << ro.jmeno;
    }
}

namespace dluhy
{
    void vlozDluh(Dluh & rd)
    {
        vlozOsobu(rd.veritel);
        std::cout << "Zadejte dluh: ";
        std::cin >> rd.mnozstvi;
    }

    void ukazDluh(const Dluh & rd)
    {
        ukazOsobu(rd.veritel);
        std::cout << ": " << rd.mnozstvi << " Kc" << endl;
    }

    double sectiDluhy(const Dluh ar[], int n)
    {
        double celkem = 0;
        for (int i = 0; i < n; i++)
            celkem += ar[i].mnozstvi;
        return celkem;
    }
}
