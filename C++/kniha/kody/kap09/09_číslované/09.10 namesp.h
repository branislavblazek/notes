// namesp.h
// vytvoø jmenné prostory osoby a dluhy
namespace osoby
{
    const int DELKA = 40;
    struct Osoba
    {
        char jmeno[DELKA];
        char prijmeni[DELKA];
    };
    void vlozOsobu(Osoba &);
    void ukazOsobu(const Osoba &);
}

namespace dluhy
{
    using namespace osoby;
    struct Dluh
    {
        Osoba veritel;
        double mnozstvi;
    };
    void vlozDluh(Dluh &);
    void ukazDluh(const Dluh &);
    double sectiDluhy(const Dluh ar[], int n);
}
