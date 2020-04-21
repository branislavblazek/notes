// useless.cpp -- jinak nepot�ebn� t��da s p�esunovou s�mantikou
#include <iostream>
using namespace std;

// interface
class Useless
{
private:
    int n;          // po�et prvk�
    char * pc;      // ukazatel na data
    static int ct;  // po�et objekt�
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f); // b�n� kop�rovac� konstruktor
    Useless(Useless && f);      // p�esunovac� konstruktor
    ~Useless();
    Useless operator+(const Useless & f)const;
// vy�aduje oper�tor=() p�i kop�rov�n� i p�esunu
    void ShowData() const;
};

// implementace
int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "vol�n� v�choz�ho konstruktoru; po�et objekt�: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct; 
    cout << "vol�n� konstruktoru int; po�et objekt�: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "vol�n� konstruktoru int, char; po�et objekt�: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless & f): n(f.n) 
{
    ++ct;
    cout << "vol�n� kop�rovac� konstanty; po�et objekt�:" << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

Useless::Useless(Useless && f): n(f.n) 
{
    ++ct;
    cout << "vol�n� p�esunovac�ho konstruktoru; po�et objekt�: " << ct << endl;
    pc = f.pc;       // vezmi adresu
    f.pc = nullptr;  // nevracej star�mu objektu nic
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    cout << "vol�n� destruktoru; zb�v� objekt�: " << --ct << endl;
    cout << "odstran�n� objekty:\n";
    ShowObject();
    delete [] pc;
}

Useless Useless::operator+(const Useless & f)const
{
    cout << "Zad�n� operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for (int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "do�asn� objekt:\n";
    cout << "Opou�t�n� operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{ 
    cout << "Po�et prvk�: " << n;
    cout << "Adresa dat: " << (void *) pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0)
        cout << "(pr�zdn� objekt)";
    else
        for (int i = 0; i < n; i++)
            cout << pc[i];
    cout << endl;
}

// aplikace
int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;          // vol� kop�rovac� konstruktor
        Useless three(20, 'o');
        Useless four(one + three);  // vol� operator+(), p�esunovac� konstruktor
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
    }
    // cin.get();
}
