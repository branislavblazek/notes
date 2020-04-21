#include <iostream>
using namespace std;

const int sec_to_min = 60;
const int sec_to_hour = 360;
const int sec_to_day = 8640;

int main()
{	
	cout << "Zadajte pocet sekund: ";
	long seconds;
	long days;
	long hours;
	long minutes;
	cin >> seconds;
	days = seconds / sec_to_day;
	seconds = seconds % sec_to_day;
	hours = seconds / sec_to_hour;
	seconds = seconds % sec_to_hour;
	minutes = seconds / sec_to_min;
	seconds = seconds % sec_to_min;
	cout << days << " dni, " << hours << " hodin, " << minutes << " minut a " << seconds << " sekund" << endl;
	
	return 0;
	
}
