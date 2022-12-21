#include <iostream>
#include <Func.hpp>
namespace LE {
	int StringToInt(char c) {
		return (int)c - 48;
	}

	void Sum(std::string max, std::string min, int diff) {
		char result[1001] = {};
		int c10 = 0;
		for (int i = max.size() - 1; i >= 0; i--) {
			if (i - diff >= 0) {
				int res = (LE::StringToInt(max[i]) + LE::StringToInt(min[i - diff]) + c10) % 10;
				c10 = ((int)max[i] - 48 + (int)min[i - diff] - 48 + c10) / 10;
				result[i + 1] = (char)(res + 48);
			}
			else
			{
				int res = ((int)max[i] - 48 + c10) % 10;
				c10 = ((int)max[i] - 48 + c10) / 10;
				result[i + 1] = (char)(res + 48);
			}
			result[0] = char(c10 + 48);
		}
		for (int i = 0; i < max.size() + 1; i++) {
			if (i == 0 && result[0] == '0') {

			}
			else
				std::cout << result[i];
		}
		std::cout << std::endl;
	}



	void ymnochenie(int max[], int min[], int max_len, int min_len) {
		// 21 4 2 1
		int ymn[2000] = {};
		int carry = 0;
		int carryd = 0;
		int k = 0;
		// Умножаю столбиком
		for (int i = 0; i < min_len; i++) {
			k = i;
			for (int j = 0; j <= max_len; j++) {
				if (j == max_len) {
					ymn[k] = carry;
				}
				else {
					if (j == 0) {
						carry = 0;
					}
					carryd = ymn[k];
					ymn[k] = (min[min_len - 1 - i] * max[max_len - 1 - j]+ ymn[k]+carry ) % 10;
					carry = (min[min_len - 1 - i] * max[max_len - 1 - j]+carryd +carry) / 10;
					k += 1;
				}
			}
		}
		if (carry != 0) {
			std::cout << carry;
		}
		for (int i = max_len + min_len - 2; i >=0; i--) {
			std::cout << ymn[i];
		}
	}
}
