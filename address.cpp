#include "address.hpp"

using namespace std;

address::address(string T, string J, string O, string STR, string NR) {
    t = T;
    j = J;
    o = O;
    str = STR;
    nr = NR;
}

void address::setCountry(string T) {
    t = T;
}

void address::setRegion(string J) {
    j = J;
}

void address::setTown(string O) {
    o = O;
}

void address::setStreet(string STR) {
    str = STR;
}

void address::setNumber(string NR) {
    nr = NR;
}

address& address::operator=(const address& A) {
    t = A.t;
    j = A.j;
    o = A.o;
    str = A.str;
    nr = A.nr;
    return (*this);
}

address address::operator+(const address& A) {
    return *this;
}

bool address::operator==(const address& A) {
    if (t.compare(A.t) == 0 && j.compare(A.j) == 0 && o.compare(A.o) == 0 && str.compare(A.str) == 0 && nr.compare(A.nr) == 0)
        return true;
    return false;
}

ostream& operator<<(ostream& os, address A) {
    os << "Tara: " << A.t << '\n';
    os << "Judet: " << A.j << '\n';
    os << "Oras: " << A.o << '\n';
    os << "Strada: " << A.str << '\n';
    os << "Numar: " << A.nr << '\n';
    return os;
}

istream& operator>>(istream& is, address& A) {
    cout << "Tara: ";
    is >> A.t;
    cout << "Judetul: ";
    is >> A.j;
    cout << "Orasul: ";
    is >> A.o;
    cout << "Strada: ";
    is >> A.str;
    cout << "Numarul strazii: ";
    is >> A.nr;

    return is;
}