#include <iostream>
using namespace std;
int main()
{
	struct pizza 
	{
		char name[70];
		float diameter;
		float weight;
	};
	
	pizza pie;
	cout << "What is the name of the pizza company? ";
	cin.getline(pie.name, 70);
	cout << "What is the diameter od the pizza in inches? ";
	cin >> pie.diameter;
	cout << "What is the weight of the pizza? ";
	cin >> pie.weight;
	cout << "Company: " << pie.name << "\n";
    cout << "Diameter: " << pie.diameter << " inches\n";
    cout << "Weight: " << pie.weight << " ounces\n";
	return 0;
}
