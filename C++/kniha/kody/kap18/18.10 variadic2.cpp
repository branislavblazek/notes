// variadic2.cpp
#include <iostream>
#include <string>

// definice 0 parametr�
void show_list() {}

// definice jednoho parametru
template<typename T>
void show_list(const T& value)
{
    std::cout << value << '\n';
}

// definice dvou a v�ce parametr�
template<typename T, typename... Args>
void show_list(const T& value, const Args&... args)
{
    std::cout << value << ", ";
    show_list(args...); 
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Pan �et�zec je proti!";
    show_list(n, x);
    show_list(x*x, '!', 7, mr);
    return 0;
}
