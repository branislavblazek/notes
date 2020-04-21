#include <iostream>
void mys(void);
void bezi(void);


int main(void)
{
	mys();
	mys();
	bezi();
	bezi();
	
	return 0;
}

void mys(void)
{
	std::cout << "Tri slepe mysi." << std::endl;
}

void bezi(void)
{
	std::cout << "Pozrite sa, ako bezi!" << std::endl;
}


