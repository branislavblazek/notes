#include <iostream>
#include <string>
using namespace std;

int main()
{
	#vytvaram strukturu
    struct clovek 
    {
        string name;
        int age;
        int weight;
        char sex;
    };
    #vytvaram pole struktur
    clovek Jano[2] = 
	{
		{
	        "Jan Gordulic",
	        36,
	        89,
	        'M'
	    },
	    {
	    	"Jan Dobrik",
			42,
			76,
			'M'	
		}
	};
	clovek Eva = 
	{
		"Eva z Raja",
		21,
		42,
		'F'
	};
	#vypis
    cout << Jano[0].name << " a " << Jano[1].name << endl;
    cout << Eva.name;
}
