#include <iostream>
#include <Func.hpp>
void main()
{
	std::string A, B;
	std::cin >> A;
	std::cin >> B;
	if (A.size() > B.size())
		LE::Sum(A, B, A.size() - B.size());
	else
		LE::Sum(B, A, B.size() - A.size());
	int masA[1000];
	int masB[1000];
	for (int i = 0; i < A.size(); i++) {
		masA[i] = LE::StringToInt(A[i]);
	}
	for (int i = 0; i < B.size(); i++) {
		masB[i] = LE::StringToInt(B[i]);
	}
	LE::ymnochenie(masA, masB, A.size(), B.size());

}