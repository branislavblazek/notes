// frnd2tmp.cpp -- šablonová tøída s nešablonovými pøáteli
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) : item(i) {ct++;}
	~HasFriend() {ct--; }
	friend void counts();
	friend void reports(HasFriend<T> &); // šablonový parametr
};

// každá specializace má svùj vlastní statický datový èlen
template <typename T>
int HasFriend<T>::ct = 0;

// nešablonový èlen všech tøíd HasFriend<T>
void counts()
{
	cout << "citac int: " << HasFriend<int>::ct << "; ";
	cout << "citac double: " << HasFriend<double>::ct << endl;
}

// nešablonový èlen všech tøíd HasFriend<int>
void reports(HasFriend<int> & hf)
{
	cout <<"HasFriend<int>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double> class
void reports(HasFriend<double> & hf)
{
	cout <<"HasFriend<double>: " << hf.item << endl;
}

int main()
{
	cout << "Neni deklarovany zadny objekt: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "Po deklaraci hfi1: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "Po deklaraci hfi2: ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "Po deklaraci hfdb: ";
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
	
	return 0;
}
