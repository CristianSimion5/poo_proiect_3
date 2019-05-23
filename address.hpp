#pragma once

#include <iostream>
#include <string>

using namespace std;

class address {
    string t, j, o, str, nr;

public:
    address(string T = "-", string J = "-", string O = "-", string STR = "-", string NR = "-");

    void setCountry(string T);
    void setRegion(string J);
    void setTown(string O);
    void setStreet(string STR);
    void setNumber(string NR);

    address& operator=(const address& A);

    address operator+(const address& A);

    bool operator==(const address& A);

    friend ostream& operator<<(ostream& os, address A);
    friend istream& operator>>(istream& is, address& A);
};