#include "pch.h"
#include "List.h"

#include <iostream>
#include "List.h"

List::List() {
	this->node = nullptr;
}

void List::add(Monomial m) {
	Node* new_node = new Node(m);
	if (node == nullptr) {
		new_node->next = node;
		node = new_node;
		// std::cout << "Line 18, new monomial has been inserted" << std::endl;
		//  std::cout << "new list: \n";
		//this->display();
		return;
	}
	else if (this->areEqual(node->monomial, new_node->monomial)) {
		// std::cout << "Line 28, monomials are equal" << std::endl;
		this->reductionOfSimilarTerms(node, new_node);
		return;
	}

	if (this->firstGreaterTheSecond(node->monomial, new_node->monomial)) {

		new_node->next = node;
		node = new_node;
		//  std::cout << "Line 29, node connected" << std::endl;
		//  std::cout << "new list: \n";
		// this->display();
	}
	else {
		Node* current_node = node;
		while (/*current_node != nullptr &&*/ current_node->next != nullptr &&
			!this->firstGreaterTheSecond(current_node->next->monomial, new_node->monomial)) {
			if (areEqual(current_node->next->monomial, new_node->monomial)) {
				//     std::cout << "Line 35, monomials are equal" << std::endl;
				this->reductionOfSimilarTerms(current_node->next, new_node);
				return;
			}
			current_node = current_node->next;
		}
		new_node->next = current_node->next;
		current_node->next = new_node;
		//  std::cout << "new list: \n";
		//  this->display();
		// std::cout << "Line 43, node connected" << std::endl;
	}
}

void List::deleteMonom(Monomial m) {
	if (node == nullptr) {
		std::cout << "node is null, element wasn't found" << std::endl;
		return;
	}
	if (node->monomial.getGrade() == m.getGrade()) {
		Node* temp = node; // Если нужно удалить голову
		node = node->next;
		//   std::cout << "deleted m: ";
		//  temp->monomial.displaySingleMonom();
		delete temp;
		//  std::cout << "new list: \n";
		//this->display();
		return;
	}
	Node* current_node = node;
	Node* previos_node = nullptr;
	while (current_node != nullptr) {
		if (m.getGrade() >= current_node->monomial.getGrade()) {
			if (m.getGrade() == current_node->monomial.getGrade()) {
				previos_node->next = current_node->next;
				//   std::cout << "deleted m: ";
				//   current_node->monomial.displaySingleMonom();
				delete current_node;
				//   std::cout << "\n new list: \n";
				//   this->display();
				return;
			}
			else {
				previos_node = current_node;
				current_node = current_node->next;
			}
		}
		else {
			std::cout << "Monomial doesn't exist in list" << std::endl;
			return;
		}
	}
}

void List::deletePosition(int position) {
	if (node == nullptr) {
		std::cout << "node is null" << std::endl;
		return;
	}
	if (length() - 1 < position) {
		std::cout << "position bigger than length of list" << std::endl;
		return;
	}
	if (position == 0) {
		Node* temp = node;
		node = node->next;
		//  std::cout << "deleted monom: ";
		// temp->monomial.displaySingleMonom();
		// std::cout << "\n new list: \n";
		// this->display();
		delete temp;
		return;
	}


	Node* current_node = node;
	Node* previos_node = nullptr;

	if (position == length() - 1) {
		int index = 0;
		while (index != position) {
			previos_node = current_node;
			current_node = current_node->next;
			index++;
		}
		// std::cout << "deleted monom: ";
		// current_node->monomial.displaySingleMonom();
		// std::cout << "\n new list: \n";
		// this->display();
		delete current_node;
		return;
	}


	for (int i = 0; i < position; i++) {
		previos_node = current_node;
		current_node = current_node->next;
	}
	previos_node->next = current_node->next;
	// std::cout << "Monomial, that was deleted: " << std::endl;
	// current_node->monomial.displaySingleMonom();
	delete current_node;
}


Monomial& List::operator[](const int index) {
	if (index > this->length() - 1) {
		std::cout << "index bigger than list length" << std::endl;
		Monomial m = Monomial();
		return m;
	}
	Node* current = node;
	int searchForIndex = 0;
	while (searchForIndex != index) {
		current = current->next;
		searchForIndex++;
	}
	return current->monomial;
}

int List::length() {
	int length = 0;
	if (node != nullptr) {
		Node* head = node->next;
		length++;
		while (head != nullptr) {
			length++;
			head = head->next;
		}
	}
	return length;
}

bool List::firstGreaterTheSecond(Monomial first, Monomial toSecond) {
	int firstPower = first.countPower();
	int secondPower = toSecond.countPower();

	if (firstPower > secondPower)
		return true;
	else if (firstPower < secondPower)
		return false;

	return first.getGrade() > toSecond.getGrade();
}

bool List::areEqual(Monomial first, Monomial second) {
	return first.countPower() == second.countPower() &&
		first.getGrade() == second.getGrade();
}

void List::display() {
	Node* current = this->node;
	while (current != nullptr) {
		std::cout << "(" << current->monomial.getCoeff() << ", " << current->monomial.countPower() << ", "
			<< current->monomial.getGrade() << ")" << "->";
		current = current->next;
	}
	std::cout << "nullptr" << std::endl;
}

void List::reductionOfSimilarTerms(Node* current_node, Node* new_node) {
	if (current_node->monomial.getCoeff() + new_node->monomial.getCoeff() == 0) {
		//new_node->monomial.displaySingleMonom();
		this->deleteMonom(new_node->monomial);
	}
	else {
		// std::cout << "coeff was changed " << std::endl;
		//  std::cout << "current_node->monomial.getCoeff(): " << current_node->monomial.getCoeff() << std::endl;
		//  std::cout << "new_node->monomial.getCoeff(): " << new_node->monomial.getCoeff() << std::endl;
		current_node->monomial.setCoeff(current_node->monomial.getCoeff() + new_node->monomial.getCoeff());
		// std::cout << "coeff after: " << current_node->monomial.getCoeff() << std::endl;
	}

}