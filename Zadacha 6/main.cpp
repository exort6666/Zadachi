#include <iostream>
#include <vector>
int main() {
    std::vector<int> vector;
    // Вместимость массива
    vector.reserve(10);
    // Количество элементов
    vector.resize(4);
    // Возвращает вместимость массива
    std::cout<< "capacity: " << vector.capacity() << std::endl;
    // Добавляет элемент в конец массива
    int a = 2;
    vector.push_back(a);
    // Добавляет элемент в определённое место в массиве
    vector.insert(vector.begin() + 5, 1);
    // Удаляет диапазон элементов
    vector.erase(vector.begin(), vector.begin() + 5);
    // Присваиваем элеметам значение
    for (size_t i = 0; i < vector.size(); i++) {
        vector[i] = -1;
        std::cout << vector[i] << std::endl;
    }
    // Изменяет вместимость под текущее количество элементов
    vector.shrink_to_fit();
    std::cout << "capacity: " << vector.capacity() << std::endl;
    // Удаляет все элементы массива
    vector.clear();
    // Добавляет объект в вектор без лишнего копирования без лишнего копирования 
    vector.emplace_back(1);
}