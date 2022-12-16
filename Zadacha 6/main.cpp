#include <iostream>
#include <vector>
int main() {
    std::vector<int> vector;
    // ����������� �������
    vector.reserve(10);
    // ���������� ���������
    vector.resize(4);
    // ���������� ����������� �������
    std::cout<< "capacity: " << vector.capacity() << std::endl;
    // ��������� ������� � ����� �������
    int a = 2;
    vector.push_back(a);
    // ��������� ������� � ����������� ����� � �������
    vector.insert(vector.begin() + 5, 1);
    // ������� �������� ���������
    vector.erase(vector.begin(), vector.begin() + 5);
    // ����������� �������� ��������
    for (size_t i = 0; i < vector.size(); i++) {
        vector[i] = -1;
        std::cout << vector[i] << std::endl;
    }
    // �������� ����������� ��� ������� ���������� ���������
    vector.shrink_to_fit();
    std::cout << "capacity: " << vector.capacity() << std::endl;
    // ������� ��� �������� �������
    vector.clear();
    // ��������� ������ � ������ ��� ������� ����������� ��� ������� ����������� 
    vector.emplace_back(1);
}