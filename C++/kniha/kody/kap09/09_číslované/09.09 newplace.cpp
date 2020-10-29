// newplace.cpp – pooužití operátoru new s umístìním
#include <iostream>
#include <new> // pro new s umistenim
const int BUF = 512;
const int N = 5;
char buffer[BUF]; // kus pameti
int main()
{
    using namespace std;

    double *pd1, *pd2;
    int i;
    cout << "Volani new a new s umistenim:\n";

    pd1 = new double[N]; // use heap
    pd2 = new (buffer) double[N]; // use buffer array
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    cout << "Adresy buferu:\n" << " heap: " << pd1
        << " static: " << (void *) buffer <<endl;
    cout << "Obsah buferu:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nVolani new a new s umistenim podruhe:\n";
    double *pd3, *pd4;
    pd3= new double[N];
    pd4 = new (buffer) double[N];
    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 20.0 * i;
    cout << "Buffer contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    cout << "\nVolani new a new s umistenim potreti:\n";
    delete [] pd1;
    pd1= new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    cout << "Buffer contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " na " << &pd1[i] << "; ";
        cout << pd2[i] << " na " << &pd2[i] << endl;
    }
    delete [] pd1;
    delete [] pd3;

    return 0;
}
