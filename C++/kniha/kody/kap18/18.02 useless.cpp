// useless.cpp -- jinak nepotøebná tøída s pøesunovou sémantikou
#include <iostream>
using namespace std;

// interface
class Useless
{
private:
    int n;          // poèet prvkù
    char * pc;      // ukazatel na data
    static int ct;  // poèet objektù
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f); // bìžný kopírovací konstruktor
    Useless(Useless && f);      // pøesunovací konstruktor
    ~Useless();
    Useless operator+(const Useless & f)const;
// vyžaduje operátor=() pøi kopírování i pøesunu
    void ShowData() const;
};

// implementace
int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "volání výchozího konstruktoru; poèet objektù: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct; 
    cout << "volání konstruktoru int; poèet objektù: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "volání konstruktoru int, char; poèet objektù: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless & f): n(f.n) 
{
    ++ct;
    cout << "volání kopírovací konstanty; poèet objektù:" << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

Useless::Useless(Useless && f): n(f.n) 
{
    ++ct;
    cout << "volání pøesunovacího konstruktoru; poèet objektù: " << ct << endl;
    pc = f.pc;       // vezmi adresu
    f.pc = nullptr;  // nevracej starému objektu nic
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    cout << "volání destruktoru; zbývá objektù: " << --ct << endl;
    cout << "odstranìné objekty:\n";
    ShowObject();
    delete [] pc;
}

Useless Useless::operator+(const Useless & f)const
{
    cout << "Zadání operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for (int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "doèasný objekt:\n";
    cout << "Opouštìní operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{ 
    cout << "Poèet prvkù: " << n;
    cout << "Adresa dat: " << (void *) pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0)
        cout << "(prázdný objekt)";
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
        Useless two = one;          // volá kopírovací konstruktor
        Useless three(20, 'o');
        Useless four(one + three);  // volá operator+(), pøesunovací konstruktor
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
