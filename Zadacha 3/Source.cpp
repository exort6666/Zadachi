#include <iostream>
#include <fstream>
int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream in("input.txt", std::ios::in);
    std::ofstream out("output.txt", std::ios::out);
    char Stroka[1000] = { '\0' };
    char Sym[] = { 'А', 'Ё', 'У', 'Е', 'О', 'Э', 'Я', 'И', 'Ь', 'Ю', 'ю', 'и', 'я', 'э', 'о', 'а', 'ы', 'е', 'у', 'ё','\0' };
    char Quantity_Sym[100] = { '\0' };
    while (!in.eof()) { // пока существуют данные
        in >> Stroka;
        int flag = 0;
        for (int i = 0; i < 100; i++) {
            Quantity_Sym[i] = '\0';
        }
        for (int i = 0; i < strlen(Stroka); i++) {
            if ((Stroka[i] >= 'А') && (Stroka[i] <= 'я') || (Stroka[i] == 'ё') || (Stroka[i] == 'Ё')) {
                for (int j = 0; j < strlen(Sym); j++) {
                    if (Stroka[i] == Sym[j]) {
                        Quantity_Sym[flag] = Stroka[i];
                        flag++;
                        break;
                    }
                }
            }
        }
        int Len = strlen(Quantity_Sym);
        int k = 0;
        for (int i = 0; i < strlen(Quantity_Sym); i++) {
            for (int j = 0; j < strlen(Quantity_Sym); j++) {
                if (Quantity_Sym[i] != Quantity_Sym[j]) {
                    k++;
                }
            }
            if (k < Len) {
                Len = k;
            }
            k = 0;
        }

        if (Len >= 4) {
            for (int i = 0; i < strlen(Stroka); i++) {
                if (Stroka[i] >= 'а' && Stroka[i] <= 'я') {
                    Stroka[i] = Stroka[i] - 32;
                }
                else if (Stroka[i] == '?') {
                    Stroka[i] = '?';
                }
                else if (Stroka[i] >= 'А' && Stroka[i] <= 'Я') {
                    continue;
                }
            }
            out << Stroka << "(";
            for (int i = 0; i < strlen(Quantity_Sym) - 1; i++) {
                out << Quantity_Sym[i] << ',' << " ";
            }
            out << Quantity_Sym[strlen(Quantity_Sym) - 1] << ")" << " ";
        }

        else
        {
            out << Stroka << " ";
        }


    }

    in.close();
    out.close();
}