#include "Polynom.h"

double eps = 1e-15;

int sum_d(int a){
    int ans = 0;
    while (a % 1000) {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}

void polynom::check_deg(int _deg) {
    if (_deg < 0 || _deg > 999) {
        throw ("Incorrect_degree");
    }
}
polynom::polynom() {
    monom* t = new monom;
    t->deg = -1;
    t->k = 0.0;
    t->next = NULL;
    t->prev = NULL;
    head = t;
}

polynom::polynom(polynom& p): polynom() {
    monom* temp = p.head->next;
    while (temp != NULL) {
        insert (temp->k, temp->deg);
        temp = temp->next;
    }
}

polynom::~polynom() {
    monom* temp = head;
    while (temp->next != NULL) {
		monom* a = temp;
        temp = temp->next;
        delete a;
    }
    delete temp;

}

void polynom::insert(double _k, int _deg) {
    check_deg(_deg);
    if (abs(_k) < eps) {
        return;
    }
    monom* temp = head;
    while((temp->next != NULL) && (temp->next->deg > _deg)) {
        temp = temp->next;
    }
    monom* cur = new monom;
    cur->k = _k;
    cur->deg = _deg;
	if (temp->next == NULL) {
		cur->next = NULL;
		cur->prev = temp;
		temp->next = cur;
	}  else {
		cur->next = temp->next;
		cur->prev = temp;
		temp->next->prev = cur;
		temp->next = cur;
	}
    canon_view();
}

void polynom::del(double _k, int _deg) {
    monom* temp = head->next;
    while ((temp != NULL) && ((temp->k != _k) || (temp->deg != _deg))) {
        temp = temp->next;
    }
    if (temp != NULL) {
        if (temp->next != NULL) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        } else {
            temp->prev->next = NULL;           
        }
        delete temp;
    }
}

bool polynom::find(double _k, int _deg) {
    monom* temp = head->next;
    while(temp != NULL) {
        if ((temp->k == _k) && (temp->deg == _deg)) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void polynom::canon_view() {
    monom* temp = head;
    while (temp->next != NULL) {
        if (abs(temp->next->k) < eps) {
            del(temp->next->k, temp->next->deg);
            continue;
        }        
        if (temp->deg == temp->next->deg) {
            temp->k += temp->next->k;
            del(temp->next->k, temp->next->deg);
			temp = temp->prev;
            continue;
        }
        temp = temp->next;
    }
	if (abs(temp->k) < eps) {
		del(temp->k, temp->deg);
	}
}
polynom& polynom::operator=(const polynom& p) {
    if (head != p.head) {
        monom* temp = head -> next;
        if (temp != NULL) {
            while (temp -> next != NULL) {
                temp = temp -> next;
                delete temp -> prev;
            }
            delete temp;
        }
		head->next = NULL;
        monom* temp_h = p.head -> next;
        while (temp_h != NULL) {
            insert (temp_h -> k, temp_h -> deg);
            temp_h = temp_h -> next;
        }
    }
    return *this;
}
bool polynom::operator==(const polynom &p) const {
    monom* temp_p = p.head->next;
    monom* temp = head->next;
    while ((temp != NULL) && (temp_p != NULL)) {
        if (temp->deg != temp_p->deg) {
            return false;
        }
        if(abs(temp->k - temp_p->k) > eps) {
            return false;
        }
        temp = temp->next;
        temp_p = temp_p->next;
    }
    if ((temp != NULL) || (temp_p != NULL))
    {
        return false;
    }
    return true;
}
polynom polynom::operator*(double val) const {
    polynom temp;
    if (abs(val) > eps) {
        temp = *this;
        monom* t = temp.head -> next;
        while (t != NULL) {
            t -> k *= val;
            t = t -> next;
        }            
    }
    return temp;
}

polynom polynom::operator+(const polynom& p) const {
    polynom a;
    monom* temp_p = p.head -> next;
    monom* temp = head -> next;
    while (temp != NULL || temp_p != NULL) {
        if (temp_p == NULL) {
            while (temp != NULL) {
                a.insert (temp -> k, temp -> deg);
                temp = temp -> next;
            }
            break;
        }
        while (temp != NULL && ((temp -> deg) > (temp_p -> deg))) {
            a.insert (temp -> k, temp -> deg);
            temp = temp -> next;
        }
        if (temp == NULL) {
            while (temp_p != NULL) {
                a.insert (temp_p -> k, temp_p -> deg);
                temp_p = temp_p -> next;
            }
            break;
        }
        while (temp_p != NULL && ((temp_p -> deg) >= (temp -> deg))) {
            a.insert (temp_p -> k, temp_p -> deg);
            temp_p = temp_p -> next;
        }
    }
    a.canon_view();
    return a;
}

polynom polynom::operator-(const polynom& p) const {
    polynom a;
	a = *this;
    a = a + p * (-1);
    return a;
}

polynom polynom::operator*(const polynom& p) const {
    polynom a;
    monom* temp = head -> next;
    while (temp != NULL) {
        monom* temp_p = p.head -> next;
        while (temp_p != NULL) {
            double res = (temp -> k) * (temp_p -> k);
            int res_d = (temp -> deg) + (temp_p -> deg);
            if (sum_d(res_d) != (sum_d(temp -> deg) + sum_d(temp_p -> deg))) {
                throw("Incorrect_deg_(mult)");
            }
            a.insert (res, res_d);
            temp_p = temp_p -> next;
        }
        temp = temp -> next;
    }
    a.canon_view();
    return a;
}

ostream& operator << (ostream& out, const polynom& p) {
    monom* temp = p.head -> next;
    if (temp == NULL) {
        out << 0;
        return out;
    }
    while (temp != NULL) {
        out << '(';
        out << temp -> k;
        int deg = temp -> deg;
        if (deg / 100 % 10) {
            out << " * x^" << deg / 100 % 10;
        }
        if (deg / 10 % 10) {
            out << " * y^" << deg / 10 % 10;
        }
        if (deg % 10) {
            out << " * z^" << deg % 10;
        }
        out << ')';
		if (temp->next != NULL) {
			out << " + ";
		}
        temp = temp -> next;
    }
    return out;
}

istream& operator >> (istream& in, polynom& p) {
    polynom a;
    p = a;
    cout << "Enter_quantity_of_monoms: ";
    int n;
    in >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Coefficient: ";
        double k;
        in >> k;
        cout << endl;
        if (abs(k) < eps) {
            continue;
        }
        int deg = 0;
        do {
            cout << "Degree: ";
            in >> deg;
            if (deg < 0 || deg > 999) {
                cout << "Incorrect_degree" << endl;
            }
        } while (deg < 0 || deg > 999);
        cout << endl;
        p.insert(k, deg);
    }
    return in;
}