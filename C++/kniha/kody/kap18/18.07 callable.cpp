// callable.cpp – volatelné typy a šablony
#include <iostream>
#include <math.h>
using namespace std;

template <typename T, typename F>
T use_f(T v, F f)
{
    static int count = 0;
    count++;
    cout << "  use_f count = " << count << ", &count = " << &count << endl;
    return f(v);
}

class Fp
{
private:
    double z_;
public:
    Fp(double z = 1.0) : z_(z) {}
    double operator()(double p) { return z_*p; }
};
 class Fq
{
private:
    double z_;
public:
    Fq(double z = 1.0) : z_(z) {}
    double operator()(double q) { return z_+ q; }
};

double dub(double x) {return 2.0*x;}

int main()
{
    double y = 1.21;
    cout << "Ukazatel funkce dub:\n";
    cout << "  " << use_f(y, dub) << endl;
    cout << "Ukazatel funkce sqrt:\n";
    cout << "  " << use_f(y, sqrt) << endl;
    cout << "Objekt funkce Fp:\n";
    cout << "  " << use_f(y, Fp(5.0)) << endl;
    cout << "Objekt funkce Fq:\n";
    cout << "  " << use_f(y, Fq(5.0)) << endl;
    cout << "Lambda výraz 1:\n";
    cout << "  " << use_f(y, [](double u) {return u*u;}) << endl;
    cout << "Lambda výraz 2:\n";
    cout << "  " << use_f(y, [](double u) {return u+u/2.0;}) << endl;
  
    cin.get();
    return 0;
}
