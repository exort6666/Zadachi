#include <iostream>
#include <math.h>
#include <Func.hpp>
void main()
{
	unsigned short Num1,Num2,Num3;
	std::cin >> Num1;
	std::cin >> Num2;
	std::cin >> Num3;
	LE::Input(Num1,Num2,Num3);
	std::cout << std::endl;
	LE::Output(LE::Input(Num1,Num2,Num3));
}