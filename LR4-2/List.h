#pragma once

#include "Monomial.h"



struct Node {
    Node* next;
    Monomial monomial;

    Node() {

    }

    Node(Monomial m) {
        next = nullptr;
        monomial = m;
    }


};


class List {
private:

    Node* node;


public:

    List();

    Monomial& operator[](const int index);

    void add(Monomial m);

    void deleteMonom(Monomial m);

    void deletePosition(int position);


    int length();

    bool firstGreaterTheSecond(Monomial first, Monomial toSecond);

    bool areEqual(Monomial first, Monomial second);

    void display();

    void reductionOfSimilarTerms(Node* current_node, Node* new_node); // приведение подобных

};

