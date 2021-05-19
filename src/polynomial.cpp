#include <polynomial.h>

monomial::monomial(int coeff, int x, int y, int z) : coefficient(coeff) {
    if (x >= maxPower || y >= maxPower || z >= maxPower) throw logic_error("Power is greater than the maximum power");
    S = x * maxPower * maxPower + y * maxPower + z;
}

monomial::monomial(int coeff, int _S) : coefficient(coeff) {
    if (_S > (maxPower - 1) * maxPower * maxPower + (maxPower - 1) * maxPower + (maxPower - 1)) throw logic_error("Power is greater than the maximum power");
    S = _S;
}

int monomial::getX() const {
    return S / (maxPower * maxPower);
}

int monomial::getY() const {
    int tmpX = S / (maxPower * maxPower);
    return (S - tmpX * maxPower * maxPower) / maxPower;
}

int monomial::getZ() const {
    int tmpX = S / (maxPower * maxPower);
    int tmpY = (S - tmpX * maxPower * maxPower) / maxPower;
    return S - tmpX * maxPower * maxPower - tmpY * maxPower;
}

int monomial::getS() const {
    return S;
}

void monomial::getXYZ(int& x, int& y, int& z) const {
    x = S / (maxPower * maxPower);
    y = (S - x * maxPower * maxPower) / maxPower;
    z = S - x * maxPower * maxPower - y * maxPower;
}

int monomial::getCoeff() const {
    return coefficient;
}

bool monomial::operator==(const monomial& m) const {
	return S == m.S;
}

bool monomial::operator!=(const monomial& m) const {
	return S != m.S;
}

bool monomial::operator>(const monomial& m) const {
	return S > m.S;
}

bool monomial::operator>=(const monomial& m) const {
	return S >= m.S;
}

bool monomial::operator<(const monomial& m) const {
	return S < m.S;
}

bool monomial::operator<=(const monomial& m) const {
	return S <= m.S;
}

monomial monomial::operator*(const int& val) {
    monomial tmp = *this;
    tmp.coefficient *= val;
    return tmp;
}

monomial& monomial::operator*=(const int& val) {
    coefficient *= val;
    return *this;
}

monomial monomial::operator+(const monomial& m) const {
    if (S != m.S) throw logic_error("Different power of monomials");
    monomial tmp = *this;
    tmp.coefficient += m.coefficient;
    return tmp;
}

monomial& monomial::operator+=(const monomial& m) {
    if (S != m.S) throw logic_error("Different power of monomials");
    coefficient += m.coefficient;
    return *this;
}

monomial monomial::operator-(const monomial& m) const {
    if (S != m.S) throw logic_error("Different power of monomials");
    monomial tmp = *this;
    tmp.coefficient -= m.coefficient;
    return tmp;
}

monomial& monomial::operator-=(const monomial& m) {
    if (S != m.S) throw logic_error("Different power of monomials");
    coefficient -= m.coefficient;
    return *this;
}

monomial monomial::operator*(const monomial& m) const {
    if (getX() + m.getX() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    if (getY() + m.getY() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    if (getZ() + m.getZ() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    monomial tmp = *this;
    tmp.coefficient *= m.coefficient;
    tmp.S += m.S;
    return tmp;
} 

monomial& monomial::operator*=(const monomial& m) {
    int x,y,z;
    int x1, y1, z1;
    getXYZ(x, y, z);
    m.getXYZ(x1, y1, z1);
    if (x + x1 >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    if (y + y1 >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    if (z + z1 >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    //if (getX() + m.getX() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    //if (getY() + m.getY() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    //if (getZ() + m.getZ() >= maxPower) throw logic_error("The resulting power exceeds the maximum");
    coefficient *= m.coefficient;
    S += m.S;
    return *this;
}

monomial monomial::operator-() const {
    monomial tmp(*this);
    tmp.coefficient = -tmp.coefficient;
    return tmp;
}

ostream& operator<<(ostream &ostr, const monomial &m) {
    ostr << m.coefficient << "*" << "x^" << m.getX() << "*y^" << m.getY() << "*z^" << m.getZ();
    return ostr;
}

int polynomial::getValue(int x, int y, int z) const {
    listIterator<monomial> tmpIter = listMonom->begin();
    int value = 0;
    while (tmpIter.hasNext()) {
        monomial tmpM = tmpIter.getValue();
        value += tmpM.getCoeff() * pow(x, tmpM.getX()) * pow(y, tmpM.getY()) * pow(z, tmpM.getZ());
        tmpIter.next();
    }
    return value;
}

polynomial::polynomial() {
    listMonom = new List<monomial>;
    listMonom->push_back(monomial(0, 0));
}

polynomial::polynomial(const polynomial& p) {
    listMonom = new List<monomial>;
    *listMonom = *(p.listMonom);
}

polynomial::~polynomial() {
    delete listMonom;
}

listIterator<monomial> polynomial::getIterBeginMonom() {
    return listMonom->begin();
}

listIterator<monomial> polynomial::getIterEndMonom() {
    return listMonom->end();
}

polynomial& polynomial::operator=(const polynomial& p) {
    *listMonom = *(p.listMonom);
    return *this;
}

polynomial polynomial::operator*(const int& val) {
    polynomial tmp;
    if (val != 0) {
        tmp = *this;
        tmp.iter = tmp.listMonom->begin();
        while (tmp.iter.hasNext()) {
            tmp.iter.getValue() *= val;
            tmp.iter.next();
        }   
    }
    return tmp;
}

polynomial& polynomial::operator*=(const int& val) {
    iter = listMonom->begin();
    if (val != 0) {
        while (iter.hasNext()) {
            iter.getValue() *= val;
            iter.next();
        }
    } else {
        listIterator<monomial> tmpIter = listMonom->end();
        if (tmpIter.hasPrev()) tmpIter.prev();
        while (iter != tmpIter) {
            iter = listMonom->erase(iter);
        }
    }
    return *this;
}

polynomial polynomial::operator+(const monomial& m) {
    polynomial tmp(*this);
    tmp.iter = tmp.listMonom->begin();
    if (m.getCoeff() != 0) {
        while (tmp.iter.hasNext()) {
            monomial &currM = tmp.iter.getValue();
            if (m > currM || !tmp.iter.hasNext()) {
                tmp.iter = tmp.listMonom->insert(tmp.iter, m);
                break;
            } else if (m == currM) {
                currM += m;
                break;
            }
            tmp.iter.next();
        }
    }
    return tmp;
}

polynomial& polynomial::operator+=(const monomial& m) {
    iter = listMonom->begin();
    if (m.getCoeff() != 0) {
        while (iter.hasNext()) {
            monomial &currM = iter.getValue();
            if (m > currM || !iter.hasNext()) {
                iter = listMonom->insert(iter, m);
                break;
            } else if (m == currM) {
                currM += m;
                break;
            }
            iter.next();
        }
    }
    return *this;
}

polynomial polynomial::operator-(const monomial& m) {
    polynomial tmp(*this);
    tmp.iter = tmp.listMonom->begin();
    if (m.getCoeff() != 0) { 
        while (tmp.iter.hasNext()) {
            monomial &currM = tmp.iter.getValue();
            if (m > currM || !tmp.iter.hasNext()) {
                tmp.iter = tmp.listMonom->insert(tmp.iter, -m);
                break;
            } else if (m == currM) {
                currM -= m;
                break;
            }
            tmp.iter.next();
        }
    }
    return tmp;
}

polynomial& polynomial::operator-=(const monomial& m) {
    iter = listMonom->begin();
    if (m.getCoeff() != 0) { 
        while (iter.hasNext()) {
            monomial &currM = iter.getValue();
            if (m > currM || !iter.hasNext()) {
                iter = listMonom->insert(iter, -m);
                break;
            } else if (m == currM) {
                currM -= m;
                break;
            }
            iter.next();
        }
    }
    return *this;
}

polynomial polynomial::operator*(const monomial& m) {
    polynomial tmp;
    if (m.getCoeff() != 0) {
        tmp = *this;
        tmp.iter = tmp.listMonom->begin();
        while (tmp.iter.hasNext()) {
            tmp.iter.getValue() *= m;
            tmp.iter.next();
        }
    }
    return tmp;
}

polynomial& polynomial::operator*=(const monomial& m) {
    iter = listMonom->begin();
    if (m.getCoeff() != 0) {
        while (iter.hasNext()) {
            iter.getValue() *= m;
            iter.next();
        }
    } else {
        listIterator<monomial> tmpIter = listMonom->end();
        if (tmpIter.hasPrev()) tmpIter.prev();
        while (iter != tmpIter) {
            iter = listMonom->erase(iter);
            iter.next();
        }
    }
    return *this;
}

polynomial polynomial::operator+(const polynomial& m) {
    polynomial tmp(*this);
    listIterator<monomial> iterM = m.listMonom->begin();
    tmp.iter = tmp.listMonom->begin();
    while (iterM.hasNext()) {
        while (tmp.iter.hasNext()) {
            monomial m1 = iterM.getValue();
            monomial &m2 = tmp.iter.getValue();
            if (m1.getCoeff() != 0) {
                if (m1 > m2 || !tmp.iter.hasNext()) {
                    tmp.iter = tmp.listMonom->insert(tmp.iter, m1);
                    tmp.iter.next();
                    break;
                } else if (m1 == m2) {
                    m2 += m1;
                    tmp.iter.next();
                    break;
                }
            }
            tmp.iter.next();
        }
        iterM.next();
    }
    return tmp;
}

polynomial& polynomial::operator+=(const polynomial& m) {
    listIterator<monomial> iterM = m.listMonom->begin();
    iter = listMonom->begin();
    while (iterM.hasNext()) {
        while (iter.hasNext()) {
            monomial m1 = iterM.getValue();
            monomial &m2 = iter.getValue();
            if (m1.getCoeff() != 0) {
                if (m1 > m2 || !iter.hasNext()) {
                    iter = listMonom->insert(iter, m1);
                    iter.next();
                    break;
                } else if (m1 == m2) {
                    m2 += m1;
                    iter.next();
                    break;
                }
            }
            iter.next();
        }
        iterM.next();
    }
    return *this;
}

polynomial polynomial::operator-(const polynomial& m) {
    polynomial tmp(*this);
    listIterator<monomial> iterM = m.listMonom->begin();
    tmp.iter = tmp.listMonom->begin();
    while (iterM.hasNext()) {
        while (tmp.iter.hasNext()) {
            monomial m1 = iterM.getValue();
            monomial &m2 = tmp.iter.getValue();
            if (m1.getCoeff() != 0) {
                if (m1 > m2 || !tmp.iter.hasNext()) {
                    tmp.iter = tmp.listMonom->insert(tmp.iter, -m1);
                    tmp.iter.next();
                    break;
                } else if (m1 == m2) {
                    m2 -= m1;
                    tmp.iter.next();
                    break;
                }
            }
            tmp.iter.next();
        }
        iterM.next();
    }
    return tmp;
}

polynomial& polynomial::operator-=(const polynomial& m) {
    listIterator<monomial> iterM = m.listMonom->begin();
    iter = listMonom->begin();
    while (iterM.hasNext()) {
        while (iter.hasNext()) {
            monomial m1 = iterM.getValue();
            monomial &m2 = iter.getValue();
            if (m1.getCoeff() != 0) {
                if (m1 > m2 || !iter.hasNext()) {
                    iter = listMonom->insert(iter, -m1);
                    iter.next();
                    break;
                } else if (m1 == m2) {
                    m2 -= m1;
                    iter.next();
                    break;
                }
            }
            iter.next();
        }
        iterM.next();
    }
    return *this;
}

polynomial polynomial::operator*(const polynomial& m) {
    polynomial tmp1(*this);
    polynomial tmp2;
    listIterator<monomial> iterM = m.listMonom->begin();
    while (iterM.hasNext()) {
        tmp2 += tmp1 * iterM.getValue();
        iterM.next();
    }
    return tmp2;
}

polynomial& polynomial::operator*=(const polynomial& m) {
    polynomial tmp1(*this);
    polynomial tmp2;
    listIterator<monomial> iterM = m.listMonom->begin();
    while (iterM.hasNext()) {
        tmp2 += tmp1 * iterM.getValue();
        iterM.next();
    }
    *this = tmp2;
    return *this;
}

ostream& operator<<(ostream &ostr, const polynomial &m) {
    listIterator<monomial> iter = m.listMonom->begin();
    while (iter.hasNext()) {
        monomial monom = iter.getValue();
        if (monom.getCoeff() > 0) {
            cout  << "+" << monom;
        } else if (monom.getCoeff() < 0) {
            cout << monom;
        }
        iter.next();
    }
    return ostr;
}