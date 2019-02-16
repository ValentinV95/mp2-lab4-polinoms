#include <iostream>
#include <fstream>
#include <locale>
#include "polinom.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int enterInputMethod;
    cout << "Выберете способ задания полиномов" << endl;
    while (true) {

        cout << "1. Ручной ввод" << endl;   
        cout << "2. Чтение из файла" << endl;
        
        cin >> enterInputMethod;

        if (enterInputMethod == 1) {
            break;
        }
        else if (enterInputMethod == 2) {
            break;
        }
        else {
            cout << "Ошибка. Пожалуйста выберете один из предложенных вариантов" << endl;
        }
    }

    Polinom f, g;
 
    // просим пользователя задать полиномы для демонстрации функционала программы 
    if (enterInputMethod == 1) {
        while (true) {
            try {
                 cout << "Задайте полином f" << endl;
                 cout << "Введите количество мономов в полиноме затем их значения в формате: <коэфициент> <степень>" << endl;
                 cin >> f;
                 cout << "Задайте полином g" << endl;
                 cout << "Введите количество мономов в полиноме затем их значения в формате: <коэфициент> <степень>" << endl;
                 cin >> g;
                 cout << "Вы задали слелующие полиномы" << endl << "f: " << endl << f << "g: " << endl << g << endl;
                 break;
            } catch (Exception exc) {
                cerr << "Error: " << exc.GetNameError() << endl;
                cerr << "Пожалуйста повторите ввод полиномов" << endl;
            }
        }
    }

    if (enterInputMethod == 2) {
        try {
            // считываем полиномы из файла для демонстрации функционала программы 
            ifstream fin("../sample_polinoms.txt");

            fin >> f;
            fin >> g;
            cout << "Из файла были считанны следующие полиномы" << endl;
            cout << endl << "f: " << endl << f << endl << "g: " << endl << g << endl;
        }
        catch (Exception exc) {
            cerr << "Error: " << exc.GetNameError() << endl;
            cerr << "Файл содержит некорректные полиномы" << endl;
        }
    }

    cout << "Выберете действие над полиномами" << endl;
    while (true) {
    
        cout << "1. Сложить f и g" << endl;
        cout << "2. Вычесть из f полином g" << endl;
        cout << "3. Перемножить f и g" << endl;
        int enterAction;
        cin >> enterAction;

        if (enterAction == 1) {
            cout << endl << "f + g: " << endl << (f + g) << endl;
        }
        else if (enterAction == 2) {
            cout << endl << "f - g: " << endl << (f - g) << endl;
        }
        else if (enterAction == 3) {
            try {
                cout << endl << "f * g: " << endl << (f * g) << endl;
            } catch (Exception exc) {
                cerr << "Error: " << exc.GetNameError() << endl;
            }
        }
        else {
            cout << "Ошибка. Пожалуйста выберете один из предложенных вариантов" << endl;
            continue;
        }
        
        while (true) {
            cout << "Хотите выбрать ещё другое действие?" << endl;
            cout << "1. Да" << endl;
            cout << "2. Нет" << endl;
            cin >> enterAction;
            if ((enterAction == 1) || (enterAction == 2)) {
                break;
            }
            cout << "Ошибка. Пожалуйста выберете один из предложенных вариантов" << endl;
        }

        if (enterAction == 1) {
            continue;
        }
        else {
            break;
        }
        
    }
}