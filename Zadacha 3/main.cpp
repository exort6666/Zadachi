#include <iostream>
#include <Func.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
//������� 7.
//� ��������� ����� input.txt ������� ������� �����. 
//����� � ������ �����, ���������� ��� ���������� ����� ������, 
//�������� �� ���������� ������� � ������� ����� ������� ������ 
//����� � ������� ��������� �����. ���������� ����� �������� � 
//���� output.txt. ���� �����, ����� ��������� ����, ������ 
//�������� ����������, ������� � ����� ����������.

char LowerCase(char c) {
	if (c <= '�' && c >= '�')
		return c - ('Z' - 'z');
	return c;
}
char UpperCase(char c) {
	if (c <= '�' && c >= '�')
		return c + ('Z' - 'z');
	if ((int)c == 72)
		return c + 16;

	return c;

}
void pusyrkovay(int arr[][2], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j][0] < arr[j + 1][0])
				std::swap(arr[j], arr[j + 1]);
}

int main()
{
	setlocale(LC_ALL, "Russian"); // ����� ��� �� �� �������������� ������� �����
	std::vector<std::string> words; // ������ ������������ ������ �����
	std::ifstream in("text.txt", std::ios::in); // ���������� ������

	std::cout << (int)'�' << std::endl;
	int a[32] = {};
	int count = 0;
	while (!in.eof()) {
		std::string c = "";
		count++;
		in >> c;
		for (int j = 0; j < c.size(); j++) {
			if (-32 <= (int)c[j] && (int)c[j] <= -1) {
				a[std::abs((int)c[j]) - 1] = a[std::abs((int)c[j]) - 1] + 1;
			}
		}
		words.push_back(c);
	}
	int b[32][2];
	for (int i = 0; i < 32; i++) {
		b[i][1] = i;
		b[i][0] = a[i];
	}
	pusyrkovay(b, 32);
	for (int i = 0; i < 10; i++) {
		std::cout << b[i][0] << " " << (char)(-b[i][1] - 1) << std::endl;
	}

	for (int i = 0; i < words.size(); i++) {
		int flag = 0;
		char symbol = 0;
		std::string word = words.at(i);
		for (int j = 0; j < word.size(); j++) {
			for (int k = 0; k < 10; k++) {
				if ((int)LowerCase(word[j]) == (-b[k][1] - 1)) {
					symbol = (char)((-b[k][1] - 1));
					flag++;
				}
			}
			if (flag > 1) break;
		}
		if (flag == 1) {
			std::transform(word.begin(), word.end(), word.begin(),UpperCase);
			std::cout << word << " (" <<UpperCase(symbol) << ")" << std::endl;
		}
	}
}