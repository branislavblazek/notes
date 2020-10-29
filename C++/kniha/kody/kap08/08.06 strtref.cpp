// strtref.cpp -- použití odkazù na struktury
#include <iostream>
using namespace std;
struct sysop
{
	char name[26];
	char quote[64];
	int used;
};

const sysop & use(sysop & sysopref); 	// funkce vrací odkaz

int main()
{
// Poznámka: nìkteré implementace vyžadují pro umožnìní inicializace
// klíèové slovo static v obou deklaracích struktur
	sysop looper =
	{
		"Rick \"Fortran\" Looper",
		"Jsem takovej fesak.",
		0
	};

	use(looper); // looper ma typ sysop
	cout << "Looper: " << looper.used << " use(s)\n";
	sysop copycat;
	copycat = use(looper);
	cout << "Looper: " << looper.used << " pouziti\n";
	cout << "Copycat: " << copycat.used << " pouziti\n";
	cout << "use(looper): " << use(looper).used << " pouziti\n";
	return 0;
}

// funkce use() vrací pøedaný odkaz
const sysop & use(sysop & sysopref)
{
	cout << sysopref.name << " rika:\n";
	cout << sysopref.quote << endl;
	sysopref.used++;
	return sysopref;
}
