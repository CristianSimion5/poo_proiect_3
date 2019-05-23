#pragma once

#include <string>
#include <complex>

#include "address.hpp"

using namespace std;

enum dType{txt, nat, cmplx, addr};

class dataAbs {
protected:
    string name;
    int ID;
    int type;

public:
    dataAbs(string n = "");
    virtual ~dataAbs() {};

    static dataAbs* create(dType t);

    string getName();
    int getID();
    int getType();

    void setName(string n);
    void setID(int id);

    virtual void print(ostream& os) = 0;
    
protected:
    virtual void setType() = 0;
};


template <typename T>
class dataType: public dataAbs {
    T dat;

public:
    dataType();
    dataType(T d, string n = "");

    T getData();
    void setData(T d);

    void addData(T d);

    void print(ostream& os);
private:
    void setType();
};

template class dataType<string>;
template class dataType<complex<double>>;
template class dataType<unsigned>;
template class dataType<address>;