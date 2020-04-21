#include <iostream>
#include <string>
using namespace std;

struct inflatable
{
	string name;
	double volume;
	float price;
};

int main()
{
	inflatable hostia[2] = 
	{
		{
			"Bambi", 0.1, 21.99
		},
		{
			"Godzilla", 56, 6565.78
		}
	};
	
	cout << "Hostia " << hostia[0].name << " a " << hostia[1].name << " maju celkovy objem ";
	cout << hostia[0].volume + hostia[1].volume << " kubickych metrov" << endl;
}
