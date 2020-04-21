// bank.cpp -- použití rozhraní tøídy Queue
// øekládat s queue.cpp
#include <iostream>
#include <cstdlib> // pro rand() a srand()
#include <ctime> // pro time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // pøišel nový zákazník?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
// setting things up
	std::srand(std::time(0)); // náhodná inicializace funkce rand()

	cout << "Pripadova studie: Bankomat Bank of Heather\n";
	cout << "Zadejte maximalni delku fronty: ";
	int qs;
	cin >> qs;
	Queue line(qs); // ve frontì mùže být maximálnì qs lidí

	cout << "Zadejte pocet simulovanych hodin: ";
	int hours; // poèet simulovaných hodin
	cin >> hours;
	// jeden cyklus simulace trvá jednu minutu
	long cyclelimit = MIN_PER_HR * hours; // poèet cyklù

	cout << "Zadejte prumerny pocet zakazniku za hodinu: ";
	double perhour; // prùmìrný poèet zákazníkù za hodinu
	cin >> perhour;
	double min_per_cust; // prùmìrná doba mezi pøíchodem zákazníkù
	min_per_cust = MIN_PER_HR; // za hodinu;

	Item temp; // data nového zákazníka
	long turnaways = 0; // poèet odmítnutých zákazníkù
	long customers = 0; // poèet zákazníkù ve frontì
	long served = 0; // poèet obsloužených zákazníkù
	long sum_line = 0; // celková délka fronty
	int wait_time = 0; // doba èekání na bankomat
	long line_wait = 0; // celková doba èekání ve frontì

// bìh simulace
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust)) // nový zákazník
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle); // cycle = èas pøíchodu
				line.enqueue(temp); // pøidá nového zákazníka do fronty
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue (temp); // vyøizuje dalšího zákazníka
			wait_time = temp.ptime(); // po wait_time minut
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}
// výpis výsledkù
	if (customers > 0)
	{
		cout << " prijato zakazniku: " << customers << endl;
		cout << " obslouzeno zakazniku: " << served << endl;
		cout << " odmitnuto zakazniku: " << turnaways << endl;
		cout << "prumerna delka fronty: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double) sum_line / cyclelimit << endl;
		cout << " prumerna cekaci doba: "
				<< (double) line_wait / served << " minutes\n";
	}
	else
		cout << "Nejsou zadni zakaznici!\n";
	cout << "Hotovo!\n";

	return 0;
}

// x = prùmìrná doba v minutách mezi dvìma zákazníky
// návratová hodnota je true, pokud se do této doby objeví nový zákazník
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
