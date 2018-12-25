#include "Polynom.h"

void main() {
    int t = 1;
    polynom a, b, c, e;
    e.insert(2, 123);
    cout << "Input: coefficient and degree of monom" << endl;
	cout << endl;
    cout << "Example:" << endl;
    cout << "Enter_quantity_of_monoms: 1" << endl;
    cout << "Coefficient: 2" << endl;
    cout << "Degree: 123" << endl;
	cout << endl;
    cout << e << endl;
    cout << endl;
    do {
        cout << "Polynom 1:" << endl;
        cin >> a;
        cout << "Polynom 2:" << endl;
        cin >> b;
        cout << endl;
        c = a + b;
        cout << "a + b:" << endl;
        cout << endl;
        cout << (a + b) << endl;
        cout << endl;
        cout << "a - b:" << endl;
        cout << endl;
        cout << a - b << endl;
        cout << endl;
        cout << "a * b:" << endl;
        cout << endl;
        try {
            cout << a * b << endl;
        }
        catch(...) {
            cout << "Incorrect_degree_after_multiplication" << endl;
        }
        cout << endl;
        cout << "To exit enter 0" << endl;
        cout << "To continue enter other" << endl;
        cin >> t;
    } while (t);
}