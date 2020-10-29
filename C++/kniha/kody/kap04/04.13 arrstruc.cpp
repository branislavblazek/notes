// arrstruc.cpp -- pole struktur
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
	inflatable guests[2] = 				// inicializace pole struktur
	{
		{"Bambi", 0.1, 21.99}, 			// první struktura v poli
		{"Godzilla", 56, 565.99} 		// další struktura v poli
	};

	cout << "Hoste " << guests[0].name << " a " << guests[1].name
			<< "\nmaji celkovy objem "
			<< guests[0].volume + guests[1].volume << " krychlovych metru.\n";
			
	return 0;
}
