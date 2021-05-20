#include "pch.h"
#include <iostream>
#include <string>
#include <locale>
#include "List.h"
#include "Polynomial.h"
#include "gtest/gtest.h"

int main() {
	//RUN_ALL_TESTS();
	/*Monomial m1 = Monomial(1, 110);
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
	*/


	/*
		m1.displaySingleMonom();
		m2.displaySingleMonom();
		m3.displaySingleMonom();
		m4.displaySingleMonom();

		l1.display();
		l2.display();
		test.getMonoms()[0].displaySingleMonom();
	*/

	Polynomial p1 = Polynomial(List());
	Polynomial p2 = Polynomial(List());

	List l1 = List();
	List l2 = List();

	//для теста операций
	//-------------------->
	Monomial m1 = Monomial(1, 110);
	Monomial m2 = Monomial(2, 120);
	Monomial m3 = Monomial(-1, 110);
	Monomial m4 = Monomial(3.5, 120);


	l1.add(m1);
	l1.add(m2);

	l2.add(m3);
	l2.add(m4);

	p1 = Polynomial(l1);
	p2 = Polynomial(l2);

	//Polynomial test = p1 + p2;
	//-------------------->
	//* list = new List();
	std::setlocale(LC_ALL, "rus");

	bool ext = false;

	std::cout << "Вводите полином, который хотите создать по одному мономy"
		"\nСначала указывается поле coeff,затем grade"
		"\nДля окончания ввода введите stop напишите"
		"\nДля выхода из программы ext";



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

		if (s_cmd == "plus") {



			if ((p1.getMonoms().length() == 0) || (p2.getMonoms().length() == 0)) {
				std::cout << "\nНужно ввести все полиномы\n";
			}
			cmd = 5;
		}

		if (s_cmd == "minus") {
			if ((p1.getMonoms().length() == 0) || (p2.getMonoms().length() == 0)) {
				std::cout << "\nНужно ввести все полиномы\n";
			}
			cmd = 6;
		}

		if (s_cmd == "mult") {
			if ((p1.getMonoms().length() == 0) || (p2.getMonoms().length() == 0)) {
				std::cout << "\nНужно ввести все полиномы\n";
			}
			cmd = 7;
		}

		switch (cmd) {

		case 1: {
			std::string s_coeff;
			std::string s_grade;
			std::string s_indx;
			int p_indx = -1;
			std::cout << "\nВведите номер полинома 1||2\n";
			std::getline(std::cin, s_indx);
			p_indx = atoi(s_indx.c_str());
			int count = 0;
			int grade;
			double coeff;
			List lst = List();

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
				lst.add(Monomial(coeff, grade));

				s_coeff = "";
				s_grade = "";
			}

			if (p_indx == 1) {
				p1.setMonoms(lst);
			}
			else {
				p2.setMonoms(lst);
			}

			break;
		}

		case 2: {
			ext = true;
			break;
		}

		case 3: {
			std::string s_index;

			std::cout << "\nВведите номер полинома 1||2\n";
			std::getline(std::cin, s_index);
			int index = atoi(s_index.c_str());
			std::string s_position;

			std::cout << "\nposition:\t";
			std::getline(std::cin, s_position);
			int position = atoi(s_position.c_str());
			if (index == 1) {
				List l = p1.getMonoms();
				l.deletePosition(position);
				p1.setMonoms(l);
				//lst->deletePosition(position);
			}
			else {
				List l = p2.getMonoms();
				l.deletePosition(position);
				p2.setMonoms(l);
			}
			break;
		}

		case 4: {
			std::string s_index;

			std::cout << "\nВведите номер полинома 1||2\n";
			std::getline(std::cin, s_index);
			int index = atoi(s_index.c_str());
			std::cout << "\npos:\t";
			std::getline(std::cin, s_index);
			int pos = atoi(s_index.c_str());
			if (index == 1) {
				std::cout << "found monomial: \n";
				p1.getMonoms()[pos].displaySingleMonom();
			}
			else {
				std::cout << "found monomial: \n";
				p2.getMonoms()[pos].displaySingleMonom();
			}

			break;
		}

		case 5: {


			Polynomial ans = p1 + p2;

			std::cout << "\n ANS:";
			ans.getMonoms().display();
			cmd = -1;
			break;
		}
		case 6: {
			Polynomial ans = p1 - p2;
			std::cout << "\n ANS:";
			ans.getMonoms().display();
			cmd = -1;
			break;

		}
		case 7: {
			Polynomial ans = p1 * p2;
			std::cout << "\n ANS:";
			ans.getMonoms().display();
			cmd = -1;
			break;

		}

		default:
			break;
		}
	}
	return 0;
}