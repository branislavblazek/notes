// vect3.cpp -- použití funkcí ze standardní knihovny šablon
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review {
	std::string title;
	int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
int main()
{
	using namespace std;

	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	cout << "Dekuji. Zadali jste nasledujici "
			<< books.size() << " hodnoceni:\n"
			<< "Znamka\tKniha\n";
	for_each(books.begin(), books.end(), ShowReview);
	
	sort(books.begin(), books.end());
	cout << "Trideni dle nazvu:\nZnamka\tKniha\n";

	for_each(books.begin(), books.end(), ShowReview);
	sort(books.begin(), books.end(), worseThan);
	cout << "Trideni dle hodnoceni:\nZnamka\tKniha\n";
	for_each(books.begin(), books.end(), ShowReview);

	random_shuffle(books.begin(), books.end());
	cout << "Po promichani:\nZnamka\tKniha\n";
	for_each(books.begin(), books.end(), ShowReview);
	cout << "Nazdar.\n";
	return 0;
}

bool operator<(const Review & r1, const Review & r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
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
