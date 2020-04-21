//variadic1.cpp � rozbalen� bal��ku parametr� pomoc� rekurzivn�ho vol�n�
#include <iostream>
#include <string>
// definice 0 parametr� �- ukon�en� vol�n�
void show_list3() {}

// definice pro 1 �i v�ce parametr�
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
    std::string mr = "Pan �et�zec je proti!";
    show_list3(n, x);
    show_list3(x*x, '!', 7, mr);
    return 0;
}
