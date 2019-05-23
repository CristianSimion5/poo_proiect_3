#pragma once

#include<iostream>
#include<vector>

#include "data.hpp"
#include "client.hpp"

using namespace std;

class library {
    vector<dataAbs*> v;
    int rightLimit = 0;
public:
    void showMenu();
    void showAddData();
    void showDeleteData();
    void showSearchHeader();
    void showSearchValue();

    void addFromClient(client &C);

    vector<dataAbs*>::iterator findName(string n);
    vector<dataAbs*>::iterator findID(int d);

    void showElements();
    void freeVector();
};