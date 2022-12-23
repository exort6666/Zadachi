#include <iostream>
#include <math.h>
#include <Func.hpp>
void main()
{
	unsigned short Num;
	std::cin >> Num;
	LE::Input(Num);
	std::cout << std::endl;
	LE::Output(LE::Input(Num));
}