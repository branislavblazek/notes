// rvref.cpp -- jednoduché nasazení odkazù r-hodnot
#include <iostream>

inline double f(double tf) {return 5.0*(tf-32.0)/9.0;};
int main()
{
    using namespace std;
    double tc = 21.5;
    double && rd1 = 7.07;
    double && rd2 = 1.8 * tc + 32.0;
    double && rd3 = f(rd2);
    cout << "hodnota a adresa tc: " << tc <<", " << &tc << endl;
    cout << "hodnota a adresa rd1: " << rd1 <<", " << &rd1 << endl;
    cout << "hodnota a adresa rd2: " << rd2 <<", " << &rd2 << endl;
    cout << "hodnota a adresa rd3: " << rd3 <<", " << &rd3 << endl;
    // cin.get();
    return 0;
}
