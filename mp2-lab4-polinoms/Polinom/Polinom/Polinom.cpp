// Polinom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Polinom.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Polynom p1, p2, res;

    cout << "Консольное приложение" << endl;
    cout << "Для корректной работы приложения данные необходимо вводить в следующем формате" << endl;
    cout << "Для произвольного монома от трех переменных в вводится коэффициент перед мономом и степени переменных монома (вводится только трехзначное число)," << endl;
    cout << "где каждый символ - степень соответствующей переменной (максимальная степень каждой переменной - 9)" << endl;
    cout << "Например:" << endl;
    cout << "x^5 * y * 8 нужно вводить как 580" << endl;
    cout << "При вводе степени монома в виде двухзначного или однозначного числа степени первых переменных автоматически считаются равными нулю" << endl;
    cout << endl;

    bool exit = false;

    while (!exit) {
        cout << "Для выхода введите 0, для продолжения 1" << endl;
        int k;
        cin >> k;
        cout << endl;

        if (k == 0) {
            break;
        }
        else if (k != 1 && k != 0) {
            continue;
        }

        int size = 0;
        cout << "Введите кол-во мономов в полиноме (максимальная длина 10)" << endl;
        cin >> size;
        if ((size != 1) && (size != 2) && (size != 3) && (size != 4) && (size != 5) && (size != 6) && (size != 7) && (size != 8) && (size != 9)) {
            cout << "Некорректное значение" << endl;
            continue;
        }

        for (int i = 0; i < size; i++) {
            double coeff = 0;
            unsigned short int degs = 0;
            cout << "Введите значение коэффициента перед мономом " << i+1 << endl;
            cin >> coeff;
            cout << "Введите значение степеней монома (трехзначное число)" << endl;
            cin >> degs;
            Monom m(coeff, degs);
            p1.addMonom(m);
            cout << p1 << endl;
        }

        int op;

        cout << endl;
        cout << "Выберите номер операции" << endl;
        cout << "0 - сложение, 1 - вычитание, "
            << "2 - умножение, 3 - умножение на константу:" << endl;
        cin >> op;
        cout << endl;

        if ( (op == 0) || (op == 1) || (op == 2) ) {
            cout << "Введите значения второго полинома" << endl;
            int size2 = 0;
            cout << "Введите кол-во мономов в полиноме (максимальная длина 10)" << endl;
            cin >> size2;
            if ((size2 != 1) && (size2 != 2) && (size2 != 3) && (size2 != 4) && (size2 != 5) && (size2 != 6) && (size2 != 7) && (size2 != 8) && (size2 != 9)) {
                cout << "Некорректное значение" << endl;
                continue;
            }

            for (int i = 0; i < size; i++) {
                double coeff = 0;
                unsigned short int degs = 0;
                cout << "Введите значение коэффициента перед мономом " << i + 1 << endl;
                cin >> coeff;
                cout << "Введите значение степеней монома (трехзначное число)" << endl;
                cin >> degs;
                Monom m(coeff, degs);
                p2.addMonom(m);
            }

            if (op == 0) {
                res = p1 + p2;
            }
            else if (op == 1) {
                res = p1 - p2;
            }
            else if (op == 2) {
                res = p1 * p2;
            }
        }

        if (op == 3) {
            cout << "Введите число, на которое необходимо умножить полином" << endl;
            double coeff = 0;
            cin >> coeff;

            res = p1 * coeff;
        }

        cout << "Итоговое значение полинома:" << endl;
        cout << res << endl << endl;
    }
}
