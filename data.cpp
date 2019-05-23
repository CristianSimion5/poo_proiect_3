#include "data.hpp"

dataAbs::dataAbs(string n) {
    name = n;
}

dataAbs* dataAbs::create(dType t) {
    if (t == txt)
        return new dataType<string>();
    if (t == nat)
        return new dataType<unsigned int>();
    if (t == cmplx)
        return new dataType<complex<double>>();
    if (t == addr)
        return new dataType<address>();
    return NULL;
}

string dataAbs::getName() {
    return name;
}

int dataAbs::getID() {
    return ID;
}

int dataAbs::getType() {
    return type;
}

void dataAbs::setName(string n) {
    name = n;
}

void dataAbs::setID(int id) {
    ID = id;
}


template <typename T>
dataType<T>::dataType() {
    cout << "Doriti ca informatia sa aiba un nume? (Y\\N)\n";

    char choice;
    cin >> choice;
    
    if (choice == 'Y' || choice == 'y') {
        cout << "Introduceti numele informatiei: ";
        cin.ignore();
        getline(cin, name);
    }
    else
        name = "";

    setType();
    cout << "Introduceti datele necesare tipului de data dorit (";
    switch (type) {
        case txt:
            cout << "text";
            break;
        
        case nat:
            cout << "numar natural";
            break;
        
        case cmplx:
            cout << "numar complex";
            break;

        case addr:
            cout << "adresa";
            break;
    }
    cout << "):\n";
    cin >> dat;
}

template <typename T>
dataType<T>::dataType(T d, string n): dataAbs(n) {
    dat = d;
    setType();
}

template <typename T>
T dataType<T>::getData() {
    return dat;
}

template <typename T>
void dataType<T>::setData(T d) {
    dat = d;
}

template <typename T>
void dataType<T>::addData(T d) {
    if (type == addr) {
        cout << "Eroare! Nu se poate adauga o adresa la o informatie de tip adresa preexistenta.\n";
        return;
    }
    dat = dat + d;
}

template <typename T>
void dataType<T>::print(ostream& os) {
    os << "Nume: " << getName() << '\n';
    os << "ID: " << getID() << '\n';
    os << "Tip: ";
    switch (getType()) {
        case txt:
            os << "Text";
            break;
        
        case nat:
            os << "Numar natural";
            break;

        case cmplx:
            os << "Numar complex";
            break;

        case addr:
            os << "Adresa";
            break;
    }
    os << '\n';
    os << "Informatie:\n" << getData() << "\n\n";
}

template <typename T>
void dataType<T>::setType() {
    if (typeid(dat) == typeid(string)) {
        type = txt;
    }
    else if (typeid(dat) == typeid(unsigned int)) {
        type = nat;
    }
    else if (typeid(dat) == typeid(complex<double>)) {
        type = cmplx;
    }
    else if (typeid(dat) == typeid(address)) {
        type = addr;
    }
    else
        throw -1;
}