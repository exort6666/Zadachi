#include <iostream>
#include <Func.hpp>
namespace LE {
	int StringToInt(char c) {
		return (int)c - 48;
	}

	void Sum(std::string max, std::string min, int diff) {
		char result[1001] = {};
		int current_remainder = 0;
		for (int i = max.size() - 1; i >= 0; i--) {
			if (i - diff >= 0) {
				int res = (LE::StringToInt(max[i]) + LE::StringToInt(min[i - diff]) + current_remainder) % 10;
				current_remainder = ((int)max[i] - 48 + (int)min[i - diff] - 48 + current_remainder) / 10;
				result[i + 1] = (char)(res + 48);
			}
			else
			{
				int res = ((int)max[i] - 48 + current_remainder) % 10;
				current_remainder = ((int)max[i] - 48 + current_remainder) / 10;
				result[i + 1] = (char)(res + 48);
			}
			result[0] = char(current_remainder + 48);
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
		int ymn[2000] = {};
		int carry = 0;
		for (int i = max_len - 1; i >= 0; i--) {
			for (int j = min_len - 1; j >= 0; j--) {
				int k = (ymn[i + j] + max[i] * min[j] + carry);
				ymn[i + j] = k % 10;
				carry = k / 10;
			}
			ymn[max_len + min_len - 1 - i] += carry;
		}
		if (carry != 0) {
			std::cout << carry;
		}
		for (int i = 0; i < max_len + min_len - 1; i++) {
			std::cout << ymn[i];
		}
	}
}
