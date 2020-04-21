//wrapped.cpp � pou�it� ob�lky funkce jako argumentu
#include �somedefs.h�
#include <iostream>
#include <functional>

double dub(double x) {return 2.0*x;}
double square(double x) {return x*x;}

int main()
{
    using std::cout;
    using std::endl;
    using std::function;

    double y = 1.21;
    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = square;
    function<double(double)> ef3 = Fq(10.0);
    function<double(double)> ef4 = Fp(10.0);
    function<double(double)> ef5 = [](double u) {return u*u;};
    function<double(double)> ef6 = [](double u) {return u+u/2.0;};
    cout << "Ukazatel funkce dub:\n";
    cout << " " << use_f(y, ef1) << endl;
    cout << "Ukazatel funkce square:\n";
    cout << " " << use_f(y, ef2) << endl;
    cout << "Objekt funkce Fp:\n";
    cout << " " << use_f(y, ef3) << endl;
    cout << "Objekt funkce Fq:\n";
    cout << " " << use_f(y, ef4) << endl;
    cout << "Lambda v�raz 1:\n";
    cout << " " << use_f(y, ef5) << endl;
    cout << "Lambda v�raz 2:\n";
    cout << " " << use_f(y,ef6) << endl;
    return 0;
}
