#include <iostream>
#include <string>
using namespace std;

struct inflatable
{
	string name;
	float volume;
	double price;
};

int main()
{
	inflatable bouquet = {"slnecnica", 0.20, 12.49};
	inflatable choice;
	
	cout << "Kytica: " << bouquet.name << " za " << bouquet.price << endl;
	choice = bouquet;
	cout << "Vyber: " << choice.name << " za " << choice.price << endl;
}
