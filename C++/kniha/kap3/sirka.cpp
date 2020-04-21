#include <iostream>

const double Min_to_Sec = 60.0;
const double Deg_to_Min = 60.0;

int main()
{
	std::cout << "Zadajte zemepisnu sirku v stupnoch, minutach a sekundach: " << std::endl;
	std::cout << "Najskor stupne: ";
	int degrees;
	std::cin >> degrees;
	std::cout << "Dalej uhlove minuty: ";
	int minutes;
	std::cin >> minutes;
	int seconds;
	std::cout << "Nakoniec uhlove sekundy: ";
	std::cin >> seconds;
	
	double spolu = degrees + (minutes + seconds/Min_to_Sec)/Deg_to_Min;
	std::cout << "Je to " << spolu << std::endl;
	
	return 0;
}
