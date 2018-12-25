#ifndef _POLYNOM_H_
#define _POLYNOM_H_
#include <algorithm>
#include <iostream>
using namespace std;

struct monom {
    double k;
    int deg;
    monom* next;
    monom* prev;  
};

class polynom {
    private:
        monom* head;
    public:
        polynom();
        polynom(polynom& p);
        ~polynom();

		monom* get_head() { return head; }
        void insert(double _k, int _deg);
        void del(double _k, int _deg);
        void check_deg(int _deg);
        bool find(double _k, int _deg);

        void canon_view();

        polynom& operator=(const polynom& p);
        bool operator==(const polynom &p) const;
        
        polynom operator*(double val) const;
        polynom operator+(const polynom& p) const;
        polynom operator-(const polynom& p) const;
        polynom operator*(const polynom& p) const;



        friend ostream& operator << (ostream& out, const polynom& p);
        friend istream& operator >> (istream& in, polynom& p);
};

int sum_d(int a);

#endif
