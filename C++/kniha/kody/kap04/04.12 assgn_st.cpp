// assgn_st.cpp -- pøiøazení struktur
#include <iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
int main()
{
    using namespace std;
	inflatable bouquet =
	{
		"slunecnice",
		0.20,
		12.49
	};
	inflatable choice;
	cout << "kytice: " << bouquet.name << " za ";
	cout << bouquet.price << " Kc" << endl;

	choice = bouquet; 		// pøiøadí jednu strukturu druhé
	cout << "vyber: " << choice.name << " za ";
	cout << choice.price << " Kc" << endl;
	
	return 0;
}
