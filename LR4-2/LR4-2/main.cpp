#include "pch.h"
#include <iostream>
#include <string>
#include <locale>
#include "List.h"
#include "Polynomial.h"
#include "gtest/gtest.h"

int main() {
        //RUN_ALL_TESTS();
        Monomial m1 = Monomial(1, 110);
        Monomial m2 = Monomial(2, 120);
        Monomial m3 = Monomial(-1, 110);
        Monomial m4 = Monomial(3.5, 120);

        List l1 = List();
        List l2 = List();

        l1.add(m1);
        l1.add(m2);
        l2.add(m3);
        l2.add(m4);

        Polynomial p1 = Polynomial(l1);
        Polynomial p2 = Polynomial(l2);

        Polynomial test = p1 * p2;

        test.getMonoms().display();
    
    

    /*
        m1.displaySingleMonom();
        m2.displaySingleMonom();
        m3.displaySingleMonom();
        m4.displaySingleMonom();

        l1.display();
        l2.display();
        test.getMonoms()[0].displaySingleMonom();
    */

    /*List *list = new List();
    std::setlocale(LC_ALL, "rus");

    bool ext = false;

    std::cout << "Вводите полином, который хотите создать по одному мономy"
                 "\nСначала указывается поле coeff,затем grade"
                 "\nДля окончания ввода введите stop напишите"
                 "\nДля выхода из программы ext";

    std::string s_coeff;
    std::string s_grade;

    int cmd;
    std::string s_cmd;

    bool is_monom_insert = true;
    while (ext != true) {
        // list->display();
        std::cout << "\nCommand:\t";
        std::getline(std::cin, s_cmd);

        if (s_cmd == "insert") {
            cmd = 1;
        }

        if (s_cmd == "exit") {
            cmd = 2;
        }

        if (s_cmd == "delete") {
            cmd = 3;
        }
        if (s_cmd == "search") {
            cmd = 4;
        }

        switch (cmd) {

            case 1: {
                int count = 0;
                int grade;
                double coeff;

                while (is_monom_insert == true) {
                    std::cout << "\ncoeff:\t";
                    std::getline(std::cin, s_coeff);
                    if (s_coeff == "stop") {
                        break;
                    }
                    std::cout << "\ngrade:\t";
                    std::getline(std::cin, s_grade);
                    if (s_grade == "stop") {

                        break;
                    }
                    count++;

                    coeff = atof(s_coeff.c_str());
                    grade = atoi(s_grade.c_str());
                    list->add(Monomial(coeff, grade));

                    s_coeff = "";
                    s_grade = "";
                }

                break;
            }
            case 2: {
                ext = true;
                break;
            }
            case 3: {
                std::string s_position;

                std::cout << "\nposition:\t";
                std::getline(std::cin, s_position);

                int position = atoi(s_position.c_str());

                list->deletePosition(position);
            }
            case 4: {
                std::string s_index;

                std::cout << "\nindex:\t";
                std::getline(std::cin, s_index);
                int index = atoi(s_index.c_str());

                std::cout << "found monomial: \n";
                (*list)[index].displaySingleMonom();
            }
        }

    }
    return 0;
*/

}