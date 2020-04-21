//variadic1.cpp – rozbalení balíèku parametrù pomocí rekurzivního volání
#include <iostream>
#include <string>
// definice 0 parametrù –- ukonèení volání
void show_list3() {}

// definice pro 1 èi více parametrù
template<typename T, typename... Args>
void show_list3( T value, Args... args)
{
    std::cout << value << ", ";
    show_list3(args...); 
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Pan Øetìzec je proti!";
    show_list3(n, x);
    show_list3(x*x, '!', 7, mr);
    return 0;
}
