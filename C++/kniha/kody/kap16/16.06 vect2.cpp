// vect2.cpp -- metody a iterátory
#include <iostream>
#include <string>
#include <vector>

struct Review {
	std::string title;
	int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
int main()
{
	using std::cout;
	using std::vector;
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	int num = books.size();
	if (num > 0)
	{
		cout << "Dekuji. Zadali jste nasledujici knihy:\n"
				<< "Znamka\tKniha\n";
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);
		cout << "Opakovani zadanych knih:\n"
				<< "Znamka\tKniha\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		vector <Review> oldlist(books); // použije kopírovací konstruktor
		if (num > 3)
		{
			// odstraní 2 položky
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "Seznam knih po vymazani:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			// vloží 1 položku
			books.insert(books.begin(), oldlist.begin() + 1,
				oldlist.begin() + 2);
			cout << "Seznam knih po vlozeni:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "Puvodni seznam knih:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "Nebyla zadana ani kniha, ani hodnoceni.\n";
	return 0;
}

bool FillReview(Review & rr)
{
	std::cout << "Zadejte nazev knihy (konec pro ukonceni): ";
	std::getline(std::cin,rr.title);
	if (rr.title == "konec")
		return false;
	std::cout << "Zadejte hodnoceni knihy: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	std::cin.get();
	return true;
}

void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}
