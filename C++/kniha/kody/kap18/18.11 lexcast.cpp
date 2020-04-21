// lexcast.cpp – jednoduchý pøevod z typu float na string
#include <iostream>
#include <string>
#include "boost/lexical_cast.hpp"
int main()
{
    using namespace std;
    cout << "Zadejte svou hmotnost:";
    float weight;
    cin >> weight;
    string gain = "10% nárùst zvýší ";
    string wt = boost::lexical_cast<string>(weight);
    gain = gain + wt + " na ";  // øetìzcový operátor+()
    weight = 1.1 * weight;
    gain = gain + boost::lexical_cast<string>(weight) + ".";
    cout << gain << endl;
    return 0;
}
