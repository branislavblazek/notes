// lambda0.cpp � pomoc� lambda v�raz�
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
const long Size1 = 39L;
const long Size2 = 100*Size1;
const long Size3 = 100*Size2;

bool f3(int x) {return x % 3 == 0;}
bool f13(int x) {return x % 13 == 0;}

int main()
{
    using std::cout;
    std::vector<int> numbers(Size1);

    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);

// pomoc� ukazatel� na funkce
    cout << "Vzorek = " << Size1 << '\n';

    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    cout << "Po�et ��sel d�liteln�ch 3: " << count3 << '\n';
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "Po�et ��sel d�liteln�ch 13: " << count13 << "\n\n";

// zv��en� po�tu ��sel
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Vzorek = " << Size2 << '\n';
// za pou�it� funktoru
    class f_mod
    {
    private:
        int dv;
    public:
        f_mod(int d = 1) : dv(d) {}
        bool operator()(int x) {return x % dv == 0;}
    };

    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Po�et ��sel d�liteln�ch 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Po�et ��sel d�liteln�ch 13: " << count13 << "\n\n";

// op�tovn� zv��en� po�tu ��sel
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Vzorek = " << Size3 << '\n';
// za pou�it� lambd
    count3 = std::count_if(numbers.begin(), numbers.end(),
             [](int x){return x % 3 == 0;});
    cout << "Po�et ��sel d�liteln�ch 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(),
              [](int x){return x % 13 == 0;});
    cout << "Po�et ��sel d�liteln�ch 13: " << count13 << '\n';

    // std::cin.get();
    return 0;
}
