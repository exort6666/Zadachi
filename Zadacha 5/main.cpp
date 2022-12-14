#include <iostream>
#include <vector>

template <typename LE>
class Array {
private:
    int m_size;
    int m_last_index = -1;
    LE* m_data;
    int getCapacity() {
        return m_size - m_last_index - 1;
    }

    void resize(int size) {
        if (size > m_size) {
            int new_size = size * 2;
            LE* new_data = new LE[new_size];
            for (int i = 0; i <= m_last_index; i++) {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_size = new_size;
        }
        else {
            m_size = size;
            if (m_size < m_last_index + 1) {
                LE* new_data = new LE[m_size];
                for (int i = 0; i < m_size; i++) {
                    new_data[i] = m_data[i];
                }
                delete[] m_data;
                m_data = new_data;
                m_last_index = m_size - 1;
            }
        }

    }
public:
    int size() {
        return m_last_index + 1;
    }

    LE at(int index) {
        if (index <= m_last_index && m_last_index != -1) {
            return m_data[index];
        }
        else {
            return NULL;
        }
    }
    void pushBack(LE val) {
        if (getCapacity() > 0) {
            m_data[m_last_index + 1] = val;
            m_last_index++;
        }
        else {
            resize(m_size + 1);
            m_data[m_last_index + 1] = val;
            m_last_index++;
        }
    }
    void editAt(LE val, int index) {
        if (m_last_index != -1 && m_last_index >= index) {
            m_data[index] = val;
        }
    }
    void insertAt(int index, LE val) {
        if (m_last_index != -1 && index <= m_last_index) {
            LE* new_data = new LE[m_size + 1];
            for (int i = 0; i < m_size; i++) {
                if (i < index) {
                    new_data[i] = m_data[i];
                }
                if (i == index) {
                    new_data[i] = val;
                    new_data[i + 1] = m_data[i];
                }
                if (i > index) {
                    new_data[i + 1] = m_data[i];
                }
            }
            delete[] m_data;
            m_data = new_data;
            m_size++;
            m_last_index++;
        }
    }
    void deleteAt(int index) {
        LE* new_data = new LE[m_size - 1];
        if (index >= 0 && index <= m_last_index && m_last_index != -1) {
            for (int i = 0; i < m_size; i++) {
                if (i < index) {
                    new_data[i] = m_data[i];
                }
                if (i > index) {
                    new_data[i - 1] = m_data[i];
                }
            }
            delete[] m_data;
            m_data = new_data;
            m_last_index--;
        }
    }

    //конструкторы
    Array() {
        m_size = 0;
        m_data = nullptr;
    }
    Array(int size) {
        m_size = size;
        if (size != 0) {
            m_data = new LE[size];
        }
        else {
            m_data = 0;
        }
    }
    Array(const Array<LE>& a) {
        m_size = a.m_size;
        m_last_index = a.m_last_index;
        if (m_size != 0)
            m_data = new LE[m_size];
        else
            m_data = 0;
        for (int i = 0; i < m_size; ++i)
            m_data[i] = a.m_data[i];
    }

    //Деструктор
    ~Array()
    {
        if (m_data)
            delete[] m_data;
    }

    LE& operator[] (int i)
    {
        return m_data[i];
    }
};
int main()
{
    std::cout << "Start main" << std::endl;
    auto a = (Array<int>(10));
    Array<int> array = a;
    int k = 2;

    std::cout << array.size() << "\n";

    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);
    array.pushBack(4);
    array.deleteAt(1);
    array.deleteAt(-9);
    array.editAt(32342, 2);
    std::cout << array.size() << "\n";
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << std::endl;
    }
    std::cout << "End main" << std::endl;
}