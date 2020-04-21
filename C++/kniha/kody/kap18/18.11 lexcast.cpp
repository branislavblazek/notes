// lexcast.cpp � jednoduch� p�evod z typu float na string
#include <iostream>
#include <string>
#include "boost/lexical_cast.hpp"
int main()
{
    using namespace std;
    cout << "Zadejte svou hmotnost:";
    float weight;
    cin >> weight;
    string gain = "10% n�r�st zv��� ";
    string wt = boost::lexical_cast<string>(weight);
    gain = gain + wt + " na ";  // �et�zcov� oper�tor+()
    weight = 1.1 * weight;
    gain = gain + boost::lexical_cast<string>(weight) + ".";
    cout << gain << endl;
    return 0;
}
