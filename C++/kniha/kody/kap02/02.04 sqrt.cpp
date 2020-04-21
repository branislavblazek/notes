// sqrt.cpp -- použití funkce sqrt()
#include <iostream>
#include <cmath> 		// nebo math.h

int main()
{
	using namespace std;

	double area; 			
	cout << "Zadejte vymeru podlahy sveho domu ve ctverecnich metrech: ";
	cin >> area;
	double side; 
	side = sqrt(area); 
	cout << "To je ekvivalent ctverce o strane " << side
			<< " metru." << endl;
	cout << "Uzasne!" << endl;
	
	return 0;
}
