#include "library.hpp"

void library::showMenu() {
    while (true) {
        cout << "============ Biblioteca ============\n";
        cout << "Pentru a continua alegeti ce doriti sa faceti:\n";
        cout << "1. Adaugare de informatii\n";
        cout << "2. Stergere de informatii\n";
        cout << "3. Regasire de informatii\n";
        cout << "4. Cautare de informatii\n";
        cout << "5. Iesiti din program\n\n";

        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                showAddData();
                break;
            case 2:
                showDeleteData();
                break;
            case 3:
                showSearchHeader();
                break;
            case 4:
                showSearchValue();
                break;
            default:
                showElements();
                freeVector();
                return;
        }
    }
}

void library::showAddData() {
    cout << "===== Adaugare informatii =====\n";
    cout << "Doriti ca informatia sa aiba un nume? (Y\\N)\n";

    char choice;
    string name = "";
    int type;
    cin >> choice;
    
    if (choice == 'Y' || choice == 'y') {
        cout << "Introduceti numele informatiei: ";
        cin.ignore();
        getline(cin, name);
    }
    
    cout << "Alegeti tipul de data al informatiei pe care doriti sa o adaugati:\n";
    cout << "0: Text\n1: Numar natural\n2: Numar Complex\n3: Adresa\n4: Anulare\n";
    do {
        cin >> type;
        if (type < 0 || type > 4)
            cout << "Introduceti o optiune valida!";
    }
    while (type < 0 || type > 4);

    dataAbs *p;
    bool exists = true;
    auto it = findName(name);
    if (name == "" || it == v.end()) {
        exists = false;
    }

    if (exists && (*it)->getType() != type) {
        cout << "Informatie cu acelasi nume existenta, dar tip de date diferit!\n";
        cout << "Apasati orice tasta pentru a continua...\n";
        cin.get();
        return;
    }

    switch (type) {
        case txt: {
            cout << "Ati ales tipul text, scrieti informatia pe un singur rand:\n";
            string str;
            cin.ignore();
            getline(cin, str);
            if (exists)
                static_cast<dataType<string>*>(*it)->addData(str);
            else
                p = new dataType<string>(str, name);
            break;
        }
        case nat: {
            cout << "Ati ales tipul numar natural, scrieti informatia: ";
            unsigned int u;
            cin >> u;
            if (exists)
                static_cast<dataType<unsigned int>*>(*it)->addData(u);
            else
                p = new dataType<unsigned int>(u, name);
            break;
        }
        case cmplx: {
            cout << "Ati ales tipul numar complex, scrieti informatia sub forma a 2 numere reale despartite prin spatiu: ";
            double a, b;
            cin >> a >> b;
            complex<double> z(a, b);
            if (exists)
                static_cast<dataType<complex<double>>*>(*it)->addData(z);
            else
                p = new dataType<complex<double>>(z, name);
            break;
        }
        case addr: {
            cout << "Ati ales tipul adresa, dati urmatoarele informatii:\n";
            address A;
            cin >> A;
            if (exists)
                static_cast<dataType<address>*>(*it)->addData(A);
            else
                p = new dataType<address>(A, name);
            break;
        }
        default: {
            return;
        }
    }

    if (!exists) {
        p->setID(rightLimit);
        v.push_back(p);
        rightLimit++;
        cout << "Informatie adaugata cu succes!\nNume: " << name << "\nID: " << rightLimit - 1 << "\n\n";
    }
    else if (type != addr) {
        cout << "Informatie cu acelasi nume, datele au fost actualizate cu noile valori\n";
    }

    cout << "Apasati orice tasta pentru a continua...\n";
    cin.ignore();
    cin.get();
}

void library::showDeleteData() {
    cout << "===== Stergere informatii =====\n";
    cout << "Selectati modul prin care vreti sa cautati informatia:\n";
    cout << "1. Stergere dupa nume\n";
    cout << "2. Stergere dupa ID\n";
    cout << "3. Anulare\n";

    int choice;
    do {
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3)
            cout << "Introduceti una din cele 3 optiuni valide!\n";
    }
    while (choice != 1 && choice != 2 && choice != 3);

    if (choice == 3) {
        return;
    }

    vector<dataAbs*>::iterator it;
    if (choice == 1) {
        cout << "Introduceti numele informatiei pe care doriti sa o stergeti:\n";
        string name;
        cin.ignore();
        getline(cin, name);
        it = findName(name);
    }
    else {
        cout << "Introduceti ID-ul informatiei pe care doriti sa o stergeti:\n";
        int id;
        cin >> id;
        it = findID(id);
    }

    if (it == v.end()) {
        cout << "Nu exista nicio informatie cu numele/ID-ul dat!\n";
    }
    else {
        delete (*it);
        v.erase(it);
        cout << "Stergerea a fost facuta cu success!\n";
    }

    cout << "Apasati orice tasta pentru a continua...\n";
    cin.ignore();
    cin.get();
}

void library::showSearchHeader() {
    cout << "===== Regasire informatii =====\n";
    cout << "Selectati modul prin care vreti sa cautati informatia:\n";
    cout << "1. Regasire dupa nume\n";
    cout << "2. Regasire dupa ID\n";
    cout << "3. Anulare\n";

    int choice;
    do {
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3)
            cout << "Introduceti una din cele 3 optiuni valide!\n";
    }
    while (choice != 1 && choice != 2 && choice != 3);

    if (choice == 3) {
        return;
    }

    vector<dataAbs*>::iterator it;
    if (choice == 1) {
        cout << "Introduceti numele informatiei pe care doriti sa o regasiti:\n";
        string name;
        cin.ignore();
        getline(cin, name);
        it = findName(name);
    }
    else {
        cout << "Introduceti ID-ul informatiei pe care doriti sa o regasiti:\n";
        int id;
        cin >> id;
        it = findID(id);
    }

    if (it == v.end()) {
        cout << "Nu exista nicio informatie cu numele/ID-ul dat!\n";
    }
    else {
        cout << "Elementul a fost gasit!\n\n";
        (*it)->print(cout);
    }

    cout << "Apasati orice tasta pentru a continua...\n";
    cin.ignore();
    cin.get();
}

void library::showSearchValue() {
    cout << "===== Cautare informatii =====\n";
    cout << "Selectati tipul de data al informatiei cautate:\n";
    cout << "0: Text\n1: Numar natural\n2: Numar Complex\n3: Adresa\n4: Anulare\n";
    
    int type;
    do {
        cin >> type;
        if (type < 0 || type > 4)
            cout << "Introduceti o optiune valida!";
    }
    while (type < 0 || type > 4);

    dataAbs* p;
    switch (type) {
        case txt: {
            cout << "Ati ales tipul text, scrieti informatia pe un singur rand:\n";
            string str;
            cin.ignore();
            getline(cin, str);
            p = new dataType<string>(str);
            break;
        }
        case nat: {
            cout << "Ati ales tipul numar natural, scrieti informatia: ";
            unsigned int u;
            cin >> u;
            p = new dataType<unsigned int>(u);
            break;
        }
        case cmplx: {
            cout << "Ati ales tipul numar complex, scrieti informatia sub forma a 2 numere reale despartite prin spatiu: ";
            double a, b;
            cin >> a >> b;
            complex<double> z(a, b);
            p = new dataType<complex<double>>(z);
            break;
        }
        case addr: {
            cout << "Ati ales tipul adresa, dati urmatoarele informatii:\n";
            address A;
            cin >> A;
            p = new dataType<address>(A);
            break;
        }
        default: {
            return;
        }
    }

    vector<dataAbs*>::iterator it = v.end();
    bool found = false;
    for (int i = 0; i < v.size() && !found; i++) {
        if (type == v[i]->getType())
            switch (type) {
                case txt: {
                    if (static_cast<dataType<string>*>(p)->getData() == static_cast<dataType<string>*>(v[i])->getData()) {
                        found = true;
                        it = v.begin() + i;
                    }
                    break;
                }
                case nat: {
                    if (static_cast<dataType<unsigned int>*>(p)->getData() == static_cast<dataType<unsigned int>*>(v[i])->getData()) {
                        found = true;
                        it = v.begin() + i;
                    }
                    break;
                }
                case cmplx: {
                    if (static_cast<dataType<complex<double>>*>(p)->getData() == static_cast<dataType<complex<double>>*>(v[i])->getData()) {
                        found = true;
                        it = v.begin() + i;
                    }
                    break;
                }
                case addr: {
                    if (static_cast<dataType<address>*>(p)->getData() == static_cast<dataType<address>*>(v[i])->getData()) {
                        found = true;
                        it = v.begin() + i;
                    }
                    break;
                }    
        }
    }

    if (it == v.end()) {
        cout << "Nu exista nicio informatie cu datele introduse!\n";
    }
    else {
        cout << "Elementul a fost gasit!\n\n";
        (*it)->print(cout);
    }

    cout << "Apasati orice tasta pentru a continua...\n";
    cin.ignore();
    cin.get();

    delete p;
}

void library::addFromClient(client& C) {
    dataAbs* pData = C.getData();
    bool exists = true;
    string name = pData->getName();
    auto it = findName(name);

    if (name == "" || it == v.end()) {
        exists = false;
    }

    if (exists && (*it)->getType() != pData->getType()) {
        cout << "Informatie cu acelasi nume existenta, dar tip de date diferit!\n";
        cout << "Apasati orice tasta pentru a continua...\n";
        cin.get();
        return;
    }

    int type = pData->getType();
    switch (type) {
        case txt: {
            if (exists)
                static_cast<dataType<string>*>(*it)->addData(static_cast<dataType<string>*>(pData)->getData());
            break;
        }
        case nat: {
            if (exists)
                static_cast<dataType<unsigned int>*>(*it)->addData(static_cast<dataType<unsigned int>*>(pData)->getData());
            break;
        }
        case cmplx: {
            if (exists)
                static_cast<dataType<complex<double>>*>(*it)->addData(static_cast<dataType<complex<double>>*>(pData)->getData());
            break;
        }
        case addr: {
            if (exists)
                static_cast<dataType<address>*>(*it)->addData(static_cast<dataType<address>*>(pData)->getData());
            break;
        }
        default: {
            return;
        }
    }

    if (!exists) {
        pData->setID(rightLimit);
        v.push_back(pData);
        C.addedInLibrary();
        rightLimit++;
        cout << "Informatie adaugata cu succes!\nNume: " << name << "\nID: " << rightLimit - 1 << "\n\n";
    }
    else if (type != addr) {
        cout << "Informatie cu acelasi nume, datele au fost actualizate cu noile valori\n";
    }

    cout << "Apasati orice tasta pentru a continua...\n";
    cin.ignore();
    cin.get();
}

vector<dataAbs*>::iterator library::findName(string n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getName() == n)
            return v.begin() + i;
    }
    return v.end();
}

vector<dataAbs*>::iterator library::findID(int id) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getID() == id)
            return v.begin() + i;
    }
    return v.end();
}

void library::showElements() {
    for (auto i : v) {
        i->print(cout);
        cout << '\n';
    }
}

void library::freeVector() {
    for (int i = 0; i < v.size(); i++) {
        delete v[i];
        v[i] = NULL;
    }
}