#include <iostream>
#include <Func.hpp>
namespace LE{
	unsigned short Input(unsigned short Num) {
		unsigned short Warehouse = 0b0000000000000000; //insigned short занимает 2 байта  
		Warehouse = Warehouse | Num;
		Warehouse = Warehouse | (Num << 5);
		Warehouse = Warehouse | (Num << 10);
		for (int i = 15; i >= 0; --i)
			std::cout << ((Warehouse >> i) & 0b0000000000000001);
		std::cout << std::endl;
		return Warehouse;
	}
	void Output(unsigned short Num) {
		unsigned short Numeric = 0;
		for (int i = 0; i < 5; i++) {
			int b = (Num >> i) & 0b0000000000000001;
			Numeric += b * pow(2, i * b);
		}
		Num = Num >> 5;
		Numeric = 0;
		for (int i = 0; i < 5; i++) {
			int b = (Num >> i) & 0b0000000000000001;
			Numeric += b * pow(2, i * b);
		}
		Num = Num >> 5;
		Numeric = 0;
		for (int i = 0; i < 5; i++) {
			int b = (Num >> i) & 0b0000000000000001;
			Numeric += b * pow(2, i * b);
		}
		std::cout << Numeric << std::endl;
	}
}
